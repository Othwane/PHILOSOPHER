NAME = philo
HEADER = incs/philo.h
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = srcs/philo.c srcs/checkargs.c srcs/philo_utils.c srcs/init.c srcs/routine.c
OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME)	:	$(OBJS)
			${CC} ${FLAGS} ${OBJS} -o $(NAME)

%.o	:	%.c	$(HEADER)
		$(CC) ${FLAGS} -c $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)
re	:	fclean all

.PHONY	:	all clean fclean re
