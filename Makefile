NAME = push_swap

CHECKER = checker

SRC	=	mandatory/alg.c       mandatory/ft_printf.c mandatory/ft_split.c  mandatory/lst_utils.c mandatory/movesr.c    mandatory/movesrr.c   mandatory/movessp.c   mandatory/push_swap.c mandatory/utils1.c    mandatory/utils2.c mandatory/applic_alg.c

SRCB	=	bonus/checker.c   bonus/ft_split.c  bonus/lst_utils.c bonus/movesr.c    bonus/movesrr.c   bonus/movessp.c   bonus/utils.c bonus/ft_strjoin.c

GNL = gnl/get_next_line.c       gnl/get_next_line_utils.c

CFLAGS	= -Wall -Wextra -Werror

CC		= cc

RM 		= rm -rf

HEADERM =  mandatory/push_swap.h

HEADERB =  bonus/checker.h

HEADERG =  gnl/get_next_line.h

OBJS	= $(SRC:.c=.o)

OBJSB	= $(SRCB:.c=.o)

OBJSGNL	= $(GNL:.c=.o)


mandatory/%.o :  mandatory/%.c   $(HEADERM)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus/%.o :  bonus/%.c   $(HEADERB)
	$(CC) $(CFLAGS) -c -o $@ $<

gnl/%.o :  gnl/%.c   $(HEADERG)
	$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS)
	cc $(OBJS) -o $(NAME) 


$(CHECKER) : $(OBJSB) $(OBJSGNL)
	cc $(OBJSB) $(OBJSGNL) -o $(CHECKER)

bonus :	$(CHECKER)

clean :
	$(RM) $(OBJS) $(OBJSB) $(OBJSGNL)


fclean : clean
	$(RM) $(NAME) $(CHECKER)


re : fclean all

.PHONY : all clean fclean re