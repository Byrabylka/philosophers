# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fooswyn <fooswyn@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 11:33:00 by Danil             #+#    #+#              #
#    Updated: 2022/07/18 19:25:11 by fooswyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc -Ofast
CFLAGS = -Wall -Wextra -Werror
PINK = \033[1;35m
HEADER = ./incs/philo_bonus.h
SRC_PATH = ./srcs
OBJ_PATH = ./objs

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))

SOURCES = main_bonus.c philo_manager_bonus.c utils_bonus.c utils2.c

OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER) Makefile
			@mkdir -p objs
			@${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

${NAME}:${OBJS}
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@rm -rf objs

fclean:clean
	   rm -f ${NAME}

re: fclean
	@${MAKE} all

mandelbrot:
	@echo "${PINK}	 	.............::::::::::::::::::::::::::::::::::::::::::::::::.......................$(END)"
	@echo "${PINK}		.........::::::::::::::::::::::::::::::::::::::::::::::::::::::::...................$(END)"
	@echo "${PINK}		.....::::::::::::::::::::::::::::::::::-----------:::::::::::::::::::...............$(END)"
	@echo "${PINK}		...:::::::::::::::::::::::::::::------------------------:::::::::::::::.............$(END)"
	@echo "${PINK}		:::::::::::::::::::::::::::-------------;;;!:H!!;;;--------:::::::::::::::..........$(END)"
	@echo "${PINK}		::::::::::::::::::::::::-------------;;;;!!/>&*|I !;;;--------::::::::::::::........$(END)"
	@echo "${PINK}		::::::::::::::::::::-------------;;;;;;!!/>)|.*#|>/!!;;;;-------::::::::::::::......$(END)"
	@echo "${PINK}		::::::::::::::::-------------;;;;;;!!!!//>|:    !:|//!!!;;;;-----::::::::::::::.....$(END)"
	@echo "${PINK}		::::::::::::------------;;;;;;;!!/>)I>>)||I#     H&))>////*!;;-----:::::::::::::....$(END)"
	@echo "${PINK}		::::::::----------;;;;;;;;;;!!!//)H:  #|              IH&*I#/;;-----:::::::::::::...$(END)"
	@echo "${PINK}		:::::---------;;;;!!!!!!!!!!!//>|.H:                     #I>/!;;-----:::::::::::::..$(END)"
	@echo "${PINK}		:----------;;;;!/||>//>>>>//>>)|%                         %|&/!;;----::::::::::::::.$(END)"
	@echo "${PINK}		--------;;;;;!!//)& |;I*-H#&||&/                           *)/!;;-----::::::::::::::$(END)"
	@echo "${PINK}		-----;;;;;!!!//>)IH:-        ##                            #&!!;;-----::::::::::::::$(END)"
	@echo "${PINK}		;;;;!!!!!///>)H%.**           *                            )/!;;;------:::::::::::::$(END)"
	@echo "${PINK}									 &)/!!;;;------:::::::::::::$(END)"
	@echo "${PINK}		;;;;!!!!!///>)H%.**           *                            )/!;;;------:::::::::::::$(END)"
	@echo "${PINK}		-----;;;;;!!!//>)IH:-        ##                            #&!!;;-----::::::::::::::$(END)"
	@echo "${PINK}		--------;;;;;!!//)& |;I*-H#&||&/                           *)/!;;-----::::::::::::::$(END)"
	@echo "${PINK}		:----------;;;;!/||>//>>>>//>>)|%                         %|&/!;;----::::::::::::::.$(END)"
	@echo "${PINK}		:::::---------;;;;!!!!!!!!!!!//>|.H:                     #I>/!;;-----:::::::::::::..$(END)"
	@echo "${PINK}		::::::::----------;;;;;;;;;;!!!//)H:  #|              IH&*I#/;;-----:::::::::::::...$(END)"
	@echo "${PINK}		::::::::::::------------;;;;;;;!!/>)I>>)||I#     H&))>////*!;;-----:::::::::::::....$(END)"
	@echo "${PINK}		::::::::::::::::-------------;;;;;;!!!!//>|:    !:|//!!!;;;;-----::::::::::::::.....$(END)"
	@echo "${PINK}		::::::::::::::::::::-------------;;;;;;!!/>)|.*#|>/!!;;;;-------::::::::::::::......$(END)"
	@echo "${PINK}		::::::::::::::::::::::::-------------;;;;!!/>&*|I !;;;--------::::::::::::::........$(END)"
	@echo "${PINK}		:::::::::::::::::::::::::::-------------;;;!:H!!;;;--------:::::::::::::::..........$(END)"
	@echo "${PINK}		...:::::::::::::::::::::::::::::------------------------:::::::::::::::.............$(END)"
	@echo "${PINK}		.....::::::::::::::::::::::::::::::::::-----------:::::::::::::::::::...............$(END)"
	@echo "${PINK}		.........::::::::::::::::::::::::::::::::::::::::::::::::::::::::...................$(END)"
	@echo "${PINK}		.............::::::::::::::::::::::::::::::::::::::::::::::::.......................$(END)"