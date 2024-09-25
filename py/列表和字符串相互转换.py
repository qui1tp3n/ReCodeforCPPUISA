# arry = [0x32, 0x33, 0x34]
# string = ''.join(chr(i) for i in arry)
# print(string)

string = '234'
arry = [hex(ord(c)) for c in string]
for i in range(len(arry)):
    if i == len(arry) - 1:  # 如果是最后一个元素
        print(arry[i], end='')  # 不加逗号
    else:
        print(arry[i], end=', ')
        
        
deb https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal main restricted universe multiverse

deb https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal-security main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal-security main restricted universe multiverse

deb https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal-updates main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal-updates main restricted universe multiverse

# deb https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal-proposed main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal-proposed main restricted universe multiverse

deb https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal-backports main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/ focal-backports main restricted universe multiverse

