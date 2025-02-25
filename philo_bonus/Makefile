# -=-=-=-=-    COLOURS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR   = \033[0;39m
YELLOW      = \033[0;93m
CYAN        = \033[0;96m
GREEN       = \033[0;92m
BLUE        = \033[0;94m
RED         = \033[0;91m

# -=-=-=-=-    NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

NAME        := philo_bonus

# -=-=-=-=-    FLAG -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

CC          = cc
FLAGS       = -Werror -Wall -Wextra -g #-fsanitize=address
DFLAGS      = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

# -=-=-=-=-    PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

RM          = rm -fr

# -=-=-=-=-    FILES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC         := main_bonus.c				\
				utils_bonus.c			\
				parser_bonus.c			\
				initializer_bonus.c		\
				timer_bonus.c			\
				exiter_bonus.c			\
				simulator_bonus.c		\
				observer_bonus.c		\
				printer_bonus.c

SRCDIR      = src
SRCS        = $(addprefix $(SRCDIR)/, $(SRC))

OBJDIR      = .obj
OBJS        = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

DEPDIR      = .dep
DEPS        = $(addprefix $(DEPDIR)/, $(SRC:.c=.d))

# -=-=-=-=-    TARGETS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: dirs $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile includes/philo_bonus.h
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CC) $(FLAGS) $(DFLAGS) -c $< -o $@
	@echo "$(CYAN)Object file created: $@ $(DEF_COLOR)"

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)!$(DEF_COLOR)"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"
	@echo "$(RED)Do you remember, my friend, when you told me hope is a prison?.$(DEF_COLOR)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "$(BLUE)Created directory: $(OBJDIR) $(DEF_COLOR)"

$(DEPDIR):
	@mkdir -p $(DEPDIR)
	@echo "$(BLUE)Created directory: $(DEPDIR) $(DEF_COLOR)"

dirs: $(OBJDIR) $(DEPDIR)

clean:
	@$(RM) $(OBJDIR) $(DEPDIR)
	@echo "$(RED)Cleaned object files and dependencies$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Cleaned all binaries$(DEF_COLOR)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
