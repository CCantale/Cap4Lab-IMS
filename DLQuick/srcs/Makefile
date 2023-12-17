################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                           created by ccantale    #
#                                                                              #
#    project: DLQuick                           claudio.cantale93@gmail.com    #
#                                                                              #
#                                                                              #
################################################################################

APP		=	..\DLQuick

CC		=	g++
COMP_FLAGS	=	-Wall -Wextra -Werror

SRCS		=	main.cpp \
			DLQ/DLQ.cpp \
			Incidents/Incidents.cpp \
			Analysis/Analysis.cpp \
			Logger/log.cpp

OBJDIR		=	obj
OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

STATIC_LIBS	=	-static-libgcc -static-libstdc++




all: $(APP)


$(APP): $(OBJS)
	@$(CC) $^ $(STATIC_LIBS) -o $(APP)

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	@if not exist $(OBJDIR)\DLQ mkdir $(OBJDIR)\DLQ
	@if not exist $(OBJDIR)\Incidents mkdir $(OBJDIR)\Incidents
	@if not exist $(OBJDIR)\Analysis mkdir $(OBJDIR)\Analysis
	@if not exist $(OBJDIR)\Logger mkdir $(OBJDIR)\Logger
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
