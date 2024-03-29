# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: skorteka <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/28 09:31:42 by skorteka      #+#    #+#                  #
#    Updated: 2019/11/28 09:31:44 by skorteka      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS = ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
TESTS = 1 2 5 6 20 25 1024 5000 10000000
ALLTESTS = ${addprefix buf, $(TESTS)}
BUFFER_SIZE=32
VARS = -D BUFFER_SIZE=${BUFFER_SIZE}
CFLAGS = -Wall -Werror -Wextra
CC = gcc

CMD = $(CC) $(CFLAGS) $(SRCS) test.c -o a.out

test: $(ALLTESTS) fclean

$(NAME):
	 $(CMD) $(VARS)

stdin_test:
	$(CC) $(CFLAGS) $(SRCS) stdin_test.c -o a.out -D BUFFER_SIZE=32

debug:
	$(CC) $(CFLAGS) $(SRCS) -g main.c -o a.out -D BUFFER_SIZE=32

1GB_buffer:
	$(CC) $(CFLAGS) $(SRCS) -g main.c -o a.out -D BUFFER_SIZE=1000000000

sanitise:
	$(CC) $(CFLAGS) -fsanitize=address -O1 -fno-omit-frame-pointer -g \
	$(SRCS) main.c -o a.out -D BUFFER_SIZE=32
	
clean:
	@-rm -f $(OBJS)

fclean: clean
	@-rm -f $(NAME)

re: fclean all

# all tests
buf1:
	@$(CMD) -D BUFFER_SIZE=1
	time sh run_test.sh "1"
buf2:
	@$(CMD) -D BUFFER_SIZE=2
	time sh run_test.sh "2"
buf5:
	@$(CMD) -D BUFFER_SIZE=5
	time sh run_test.sh "5"
buf6:
	@$(CMD) -D BUFFER_SIZE=6
	time sh run_test.sh "6"
buf20:
	@$(CMD) -D BUFFER_SIZE=20
	time sh run_test.sh "20"
buf25:
	@$(CMD) -D BUFFER_SIZE=25
	time sh run_test.sh "25"
buf1024:
	@$(CMD) -D BUFFER_SIZE=1024
	time sh run_test.sh "1024"
buf5000:
	@$(CMD) -D BUFFER_SIZE=5000
	time sh run_test.sh "5000"
buf10000000:
	@$(CMD) -D BUFFER_SIZE=10000000
	time sh run_test.sh "10000000"

.PHONY: clean fclean re all test
