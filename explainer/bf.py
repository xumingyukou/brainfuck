# Python 实现的 Brainfuck 解释器

test = '++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.>+.+++++++..+++.<<++.>+++++++++++++++.>.+++.------.--------.<<+.<.'


def bf_interpreter(bf_code):
    main_list = [0]
    now_id = 0  # 数组指针位置
    now_position = 0  # 代码指针位置
    while now_position < len(bf_code):
        command = bf_code[now_position]
        if command == '<':
            if now_id == 0:
                print_error(1, '内存错误，指针位于-1')
            else:
                now_id -= 1
        elif command == '>':
            now_id += 1
            if now_id >= len(main_list):
                main_list.append(0)
        elif command == '+':
            main_list[now_id] += 1
            if main_list[now_id] == 256:
                main_list[now_id] = 0
        elif command == '-':
            main_list[now_id] -= 1
            if main_list[now_id] == -1:
                main_list[now_id] = 255
        elif command == '.':
            print(chr(main_list[now_id]), end='')
        elif command == ',':
            while True:
                input_chr = input('请输入：')
                if len(input_chr) == 1:
                    if ord(input_chr) < 128:
                        main_list[now_id] = ord(input_chr)
                        break
                    else:
                        print_error(2, '输入错误，只能输入ASCII字符')
                else:
                    print_error(2, '输入错误，只能输入一个字符')
        elif command == '[':
            if main_list[now_id] == 0:
                try:
                    now_position = bf_code.index(']', now_position) - 1
                except ValueError:
                    print_error(3, '代码错误，缺失：]')
        elif command == ']':
            if main_list[now_id] != 0:
                try:
                    now_position = len(bf_code) - bf_code[::-1].index('[', len(bf_code) - now_position - 1) - 1
                except ValueError:
                    print_error(3, '代码错误，缺失 [')
        else:
            print_error(0, '无法解析的字符：' + command)
        now_position += 1
    print(main_list)


def print_error(error_code, msg):
    print(error_code, msg)


if __name__ == '__main__':
    bf_interpreter(test)
