# AES.MODE_ECB 表示模式是ECB模式
# from Crypto.Cipher import AES
# hex_key = '0102030405060708090a0b0c0d0e0f101112131415161718'
# byte_key = bytes.fromhex(hex_key)
# hex_cipher = '834A29E1AA4171EFBAC862615310000A13BC901AA898B2E99207B02C6342C91F6E8BFC5205C6DD259BE638924C711A3F6FB166E30398F8678A61B860DFD3C86B'
# byte_cipher = bytes.fromhex(hex_cipher) #需要加密的内容，bytes类型
# aes = AES.new(byte_key,AES.MODE_ECB) #创建一个aes对象
# plaintxt = aes.decrypt(byte_cipher) # 解密密文
# print("明文：",plaintxt)


# AES.MODE_CBC 表示模式是CBC模式
from Crypto.Cipher import AES
password = b'1234567812345678' #秘钥，b就是表示为bytes类型
iv = b'1234567812345678' # iv偏移量，bytes类型
text = b'abcdefghijklmnhi' #需要加密的内容，bytes类型
aes = AES.new(password,AES.MODE_CBC,iv) #创建一个aes对象
en_text = aes.encrypt(text) 
print("密文：",en_text) #加密明文，bytes类型
aes = AES.new(password,AES.MODE_CBC,iv) #CBC模式下解密需要重新创建一个aes对象
den_text = aes.decrypt(en_text)
print("明文：",den_text)
