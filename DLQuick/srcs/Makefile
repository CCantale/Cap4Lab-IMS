################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                           created by ccantale    #
#                                                                              #
#    project: DLQuick                           claudio.cantale93@gmail.com    #
#                                                                              #
#                                                                              #
################################################################################

APP				=		../DLQuick

CC				=		g++
COMP_FLAGS		=		-Wall -Wextra -Werror -std=c++11

SRCS			=		main.cpp \
						DLQ/DLQ.cpp \
						Incidents/Incidents.cpp \
						Analysis/Analysis.cpp \
						Logger/log.cpp

OBJDIR			=		obj
OBJS			=		$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))




all: $(APP)


$(APP): $(OBJS)
	@$(CC) $^ -o $(APP) -lncurses

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(COMP_FLAGS) -c $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm $(APP)

kill: clean fclean


re: kill all

r: all
	@$(APP)

.PHONY: all clean fclean kill re r
