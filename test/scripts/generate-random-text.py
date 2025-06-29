import random
import string
import sys

def random_string(base_len, extra_len):
    length = base_len + random.randint(0, extra_len)
    charset = string.ascii_letters + string.digits + string.punctuation
    return ''.join(random.choices(charset, k=length))

def main():
    if len(sys.argv) != 7:
        print(f"Usage: {sys.argv[0]} <key_len> <value_len> <extra_len> <key_count> <miss_rate> <second_block_count>")
        print("Arguments:")
        print("  key_len: Length of the keys (base length)")
        print("  value_len: Length of the values (base length)")
        print("  extra_len: Maximum additional length for keys and values")
        print("  key_count: Number of unique keys to generate")
        print("  miss_rate: Probability of outputting a non-existent key (0.0 to 1.0)")
        print("  second_block_count: Number of keys to output in the second block")
        print("Example: python generate-random-text.py 20 30 5 7 0.1 3")

        sys.exit(1)

    key_len = int(sys.argv[1])
    value_len = int(sys.argv[2])
    extra_len = int(sys.argv[3])
    key_count = int(sys.argv[4])
    miss_rate = float(sys.argv[5])
    second_block_count = int(sys.argv[6])

    # 登録フェーズ（キーとバリューをランダムに生成して保存）
    kv_store = {}
    while len(kv_store) < key_count:
        key = random_string(key_len, extra_len)
        if key not in kv_store:
            value = random_string(value_len, extra_len)
            kv_store[key] = value
            print(key)
            print(value)

    print()  # 空行

    # 出力フェーズ（キーのみ）
    keys = list(kv_store.keys())
    for _ in range(second_block_count):
        if random.random() < miss_rate:
            print(random_string(key_len, extra_len))  # 存在しないキーを出力（たぶん）
        else:
            print(random.choice(keys))  # 登録されたキーを出力

if __name__ == "__main__":
    main()
