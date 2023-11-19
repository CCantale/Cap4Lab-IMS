################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                           created by ccantale    #
#                                                                              #
#    project: DLQsniper                         claudio.cantale93@gmail.com    #
#                                                                              #
#                                                                              #
################################################################################

APP		=		..\DLQsniper

CC		=		g++
COMP_FLAGS	=		-Wall -Wextra -Werror

SRCS		=		main.cpp \
				ReferenceFinder/ReferenceFinder.cpp \
				IncidentFinder/IncidentFinder.cpp \
				ReferenceAnalyser/ReferenceAnalyser.cpp

OBJDIR		=		obj
OBJS		=		$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))




all: $(APP)


$(APP): $(OBJS)
	@$(CC) $^ -o $(APP)

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	@if not exist $(OBJDIR)\ReferenceFinder mkdir $(OBJDIR)\ReferenceFinder
	@if not exist $(OBJDIR)\IncidentFinder mkdir $(OBJDIR)\IncidentFinder
	@if not exist $(OBJDIR)\ReferenceAnalyser mkdir $(OBJDIR)\ReferenceAnalyser
	@$(CC) $(COMP_FLAGS) -c $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	@del /q /s $(OBJDIR)

fclean:
	@del $(APP).exe

kill: clean fclean


re: kill all

r: all
	@$(APP)

.PHONY: all clean fclean kill re r
