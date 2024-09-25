# def rc4_key_schedule(key):
#     key_length = len(key)
#     s = list(range(256))
#     j = 0

#     # KSA (Key Scheduling Algorithm)
#     for i in range(256):
#         j = (j + s[i] + key[i % key_length]) % 256
#         s[i], s[j] = s[j], s[i]  # Swap

#     return s

# def rc4_encrypt_decrypt(data, key):
#     s = rc4_key_schedule(key)
#     i = j = 0
#     output = []

#     # Pseudo-random generation algorithm (PRGA)
#     for byte in data:
#         i = (i + 1) % 256
#         j = (j + s[i]) % 256
#         s[i], s[j] = s[j], s[i]  # Swap
#         k = s[(s[i] + s[j]) % 256]
#         output.append(byte ^ k)  # XOR with the keystream

#     return bytes(output)

# # 示例
# key = b"Aotem"
# # plaintext = b"Hello, World!"

# # # 加密
# # ciphertext = rc4_encrypt_decrypt(plaintext, key)
# # print(f"加密后的数据: {ciphertext}")
# ciphertext = bytes.fromhex('5BD31F43E7FA33D2BB05ADE5DD081358C09829BA39')
# # 解密（RC4的加密和解密过程相同）
# decrypted_text = rc4_encrypt_decrypt(ciphertext, key)
# # print(f"解密后的数据: {decrypted_text.decode()}")
# print(decrypted_text)
def reverse_by_pairs(s):
    # 将字符串分成两位一组
    pairs = [s[i:i+2] for i in range(0, len(s), 2)]
    # 逆序排列这些组并连接成新的字符串
    reversed_pairs = ''.join(pairs[::-1])
    return reversed_pairs

# 示例字符串
s = "48B85BD31F43E7FA33D2"
reversed_s = reverse_by_pairs(s)
s1 = "48B8BB05ADE5DD081358"
reversed_s1 = reverse_by_pairs(s1)
print()
print(reversed_s1,end='')
print(reversed_s)
