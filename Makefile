NAME			=	minishell

GREEN			=	"\033[32m"
L_GREEN			=	"\033[1;32m"
RED				=	"\033[31m"
L_RED			=	"\033[1;31m"
RESET			=	"\033[0m"
BOLD			=	"\033[1m"
L_PUPLE			=	"\033[1;35m"
UP				=	"\033[A"
DOWN			=	"\033[B"
RIGHT			=	"\033[C"
LEFT			=	"\033[D"
CUT				=	"\033[K"
SAVE			=	"\033[s"
RESTORE			=	"\033[u"

GCC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror
LIBFT_PATH		=	./libft
INCLUDES_PATH	=	./include
INCLUDES		= 	./include/minishell.h

-include		sources.mk

OBJS 				=	$(SOURCES:.c=.o)

BREW_PATH			=	/Users/afulmini/.brew/opt/readline
LDFLAGS				=	"-L/Users/afulmini/.brew/opt/readline/lib"
CPPFLAGS			=	"-I/Users/afulmini/.brew/opt/readline/include"

all		: $(NAME)

$(LIBFT_PATH)/libft.a:
		$(MAKE) -C $(LIBFT_PATH)

%.o     : %.c $(INCLUDES)
		@$(GCC) $(CFLAGS) -I $(INCLUDES) $(CPPFLAGS) \
		-D READLINE_PATH=\“$(BREW_PATH)/readline.h\” \
		-D HISTORY_PATH=\“$(BREW_PATH)/history.h\” \
		-c $< -o $@
		@echo $(SAVE)$(CUT)$(BOLD)$(L_GREEN) Compiling with $(CFLAGS)...$(RESET)
		@echo $(CUT) $(GREEN)[$^] to [$@] $(RESET)
		@printf $(UP)$(UP)

$(NAME) : $(LIBFT_PATH)/libft.a $(INCLUDES) $(OBJS)
		@$(GCC) $(CFLAGS) $(LIBFT_PATH)/libft.a \
		-lreadline $(LDFLAGS) -I $(INCLUDES) $(CPPFLAGS) $(OBJS) -o $(NAME)
		@echo $(BOLD)$(L_PUPLE) :sparkles:$@ created!! $(RESET)

#	linux make
linux	:	$(OBJS)
			$(MAKE) -s -C $(LIBFT_PATH)
			$(GCC) $(CFLAGS) $(OBJS) -o minishell libft/libft.a -lreadline

#	Clean
clean	:
		$(MAKE) -s -C $(LIBFT_PATH) clean
		@$(RM) $(OBJS)
		@echo $(L_RED) Cleaning all .o in project and libraries. $(RESET)

#	Full Clean
fclean	: clean
		$(MAKE) -s -C $(LIBFT_PATH) fclean
		@$(RM) $(NAME)
		@echo $(L_RED) Cleaning compiled program $(NAME). $(RESET)

#	Recompile
re		: fclean all

.PHONY:	all clean fclean re
