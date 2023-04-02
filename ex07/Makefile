NAME		= sat

SRCS		= sat.cpp main.cpp \
			../ex03/eval_formula.cpp \
			../ex04/truth_table.cpp

OBJS		= ${SRCS:.cpp=.o}

CFLAGS		= -Wall -Wextra -Werror -I.

all:		${NAME}

$(NAME):	${OBJS}
			c++ ${CFLAGS} -o ${NAME} ${OBJS}

%.o :		%.cpp
			c++ ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re