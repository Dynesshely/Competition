import random
import string

keyword_list = ['cout', '+=', '-=', 'int ', 'goto', 'asm', 'do', 'if', '[', ']',
                'return', 'typedef', 'auto', 'double', 'inline', '{', '}',
                'short', 'typeid', 'bool', 'int ', '(', ')',
                'signed', 'typename', 'break', 'else', '&gt;=', '&lt;=',
                'sizeof', 'union', 'case', 'enum', 'mutable', ';',
                'static', 'unsigned', 'catch', 'explicit', 'try',
                'namespace', 'using', 'char', 'main', 'const',
                'export', 'new', 'struct', 'class', 'switch',
                'false', 'private', 'long', '::', 'void', 'endl',
                'float', 'protected', 'this', 'continue', '++', '--',
                'for', 'public', 'throw', 'while', 'default', 'friend',
                'true', '&lt;&lt;', 'cin', 'printf', '==', '&gt;&gt;', '!=', ]


def random_char():
    r = chr(random.randint(97, 122))
    char, char_r, list_chr = [], [], []
    for i in range(len(keyword_list)):
        char.append(r + str(i))
        char_r.append(keyword_list[i])
    random.shuffle(char)
    random.shuffle(char_r)
    for i in range(len(char)):
        list_chr.append([char[i], char_r[i]])
    return list_chr


def generate_define(list_chr):
    define = []
    for i in range(len(list_chr)):
        define.append('#define ' + list_chr[i][0] + ' ' + list_chr[i][1])
    return define


def replace(list_char, str, confusion):
    if confusion == ' /**/ ':
        confusion = ' /*' + ''.join(random.sample(string.hexdigits, 6)) + '*/ '
    for i in list_char:
        if i[1] in str:
            str = str.replace(i[1], confusion + i[0] + confusion)
    return str


def open_file(list_char):
    cpp = input('请输入一个C++代码的文件名:')
    confusion = input('请输入混淆注释（可选,不填则随机混淆）:')
    confusion = ' /*' + confusion + '*/ '
    filenmae = cpp.split('.')[0] + '混淆.cpp'
    with open(cpp, 'r') as f:
        with open(filenmae, 'w') as m:
            define = generate_define(list_char)
            for i in define:
                m.write(i + '\n')
            for i in f.readlines():
                if '#' in i[0]:
                    m.write(i)
                    continue
                i = i.strip()
                i_replace = replace(list_char, i, confusion)
                m.write(i_replace + '\n')
            print('混淆代码完成了哦^_^！\n混淆后的文件名为： ' + filenmae + '\n')


if __name__ == '__main__':
    print('-' * 60)
    print('          C++ 代码混淆工具beta版        Author By: Zgao\n')
    print('                  tips: cpp代码和该软件需在同一目录下\n')
    print('-' * 60)
    while True:
        open_file(random_char())