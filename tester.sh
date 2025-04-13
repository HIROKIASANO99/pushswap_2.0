#!/bin/bash

PUSH_SWAP=./push_swap
CHECKER=./checker

# 色設定
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[1;34m'
NC='\033[0m' # No Color

# ログ設定
TIMESTAMP=$(date +%Y%m%d_%H%M%S)
LOG_DIR="./logs"
LOG_FILE="$LOG_DIR/tester_log_$TIMESTAMP.txt"
mkdir -p "$LOG_DIR"

log_and_echo() {
    echo -e "$1"
    echo -e "$(echo -e "$1" | sed -r 's/\x1B\[[0-9;]*[mK]//g')" >> "$LOG_FILE"
}

# テストケース
tests=(
    ""
    "2 1"
    "3 2 1"
    "2 1 3"
    "5 4 3 2 1"
    "1 5 2 4 3"
    "3 1 5 4 2"
    "9 2 4 1 6 5 3 8 7"
)

error_tests=(
    "a"
    "1 2 a"
    "2 1 a"
    "1 2 3 4 a"
    "1 2 3 4 5a"
    "4 3 2 1 a"
    "4 3 2 1 0a"
    "1 2 3 4 5 6 a"
    "1 2 3 4 5 6a"
    "6 5 4 3 2 1 a"
    "6 5 4 3 2 1a"
    "1 2 1"
    "1 2 3 4 4"
    "1 2 3 4 5 6 7 8 9 4"
)

silent_tests=(
    " "
    "1"
    "42"
    "-100"
    "1000000"
    "1 2"
    "1 2 3"
    "1 2 3 4 5"
    "1 2 3 4 5 6 7 8 9"
)

run_test() {
    local t="$1"
    local input_str="$2"
    local expect_silent="$3"

    log_and_echo "${BLUE}▶️  Input: $input_str${NC}"

    output=$($PUSH_SWAP $t 2>&1)
    ps_status=$?

    if [ $ps_status -ne 0 ]; then
        log_and_echo "   ❌ ${RED}push_swap crashed or returned error: $output${NC}"
        log_and_echo "   ♻️  Memory Leak: N/A"
        log_and_echo "-----------------------------------------------------"
        return
    fi

    if [ "$expect_silent" == "true" ]; then
        if [ -z "$output" ]; then
            log_and_echo "   ✅ ${GREEN}OK - 出力なし${NC}"
        else
            log_and_echo "   ❌ ${RED}想定外の出力あり: $output${NC}"
        fi
        log_and_echo "-----------------------------------------------------"
        return
    fi

    count=$(echo "$output" | wc -l)
    result=$(echo "$output" | $CHECKER $t)
    if [[ "$result" == "OK" ]]; then
        result_color="${GREEN}OK${NC}"
    else
        result_color="${RED}$result${NC}"
    fi

    valgrind_output=$(mktemp)
    valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all \
        $PUSH_SWAP $t > /dev/null 2> "$valgrind_output"

    definitely_lost=$(grep "definitely lost:" "$valgrind_output" | awk '{print $4}')
    still_reachable=$(grep "still reachable:" "$valgrind_output" | awk '{print $4}')

    if [[ -z "$definitely_lost" || -z "$still_reachable" ]]; then
        leaks_color="${RED}N/A${NC}"
    elif [[ "$definitely_lost" != "0" || "$still_reachable" != "0" ]]; then
        leaks_color="${RED}leaks (def: $definitely_lost, still: $still_reachable)${NC}"
    else
        leaks_color="${GREEN}0 bytes${NC}"
    fi

    log_and_echo "   🌀 Operations: $count"
    log_and_echo "   ✅ Checker: $result_color"
    log_and_echo "   ♻️  Memory Leak: $leaks_color"
    log_and_echo "-----------------------------------------------------"

    rm "$valgrind_output"
}

echo -e "\n======= ✅ 通常引数のテスト（複数引数） =======\n" | tee -a "$LOG_FILE"
for t in "${tests[@]}"; do
    run_test "$t" "$t"
done

echo -e "\n======= ✅ 1つの文字列引数（argc == 2）テスト =======\n" | tee -a "$LOG_FILE"
for t in "${tests[@]}"; do
    run_test "\"$t\"" "\"$t\""
done

echo -e "\n======= 🔇 無出力が期待されるテストケース =======\n" | tee -a "$LOG_FILE"
for t in "${silent_tests[@]}"; do
    run_test "$t" "$t" "true"
done

echo -e "\n======= 🔇 無出力（1つの文字列引数）テスト（argc == 2） =======\n" | tee -a "$LOG_FILE"
for t in "${silent_tests[@]}"; do
    run_test "\"$t\"" "\"$t\"" "true"
done

echo -e "\n======= ❌ エラー系テスト（入力エラー確認） =======\n" | tee -a "$LOG_FILE"
for t in "${error_tests[@]}"; do
    log_and_echo "${RED}🚫 Input: $t${NC}"
    result=$($PUSH_SWAP $t 2>&1)
    if [ $? -ne 0 ]; then
        log_and_echo "   ✅ ${GREEN}Error caught（非0終了ステータス）${NC}"
    else
        log_and_echo "   ⚠️  ${RED}終了ステータス0：出力 → $result${NC}"
    fi
    log_and_echo "-----------------------------------------------------"
done

log_and_echo "\n📝 ログファイルに出力済み: ${BLUE}$LOG_FILE${NC}\n"
