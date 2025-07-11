NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I$(LIBFT_PATH)

SRCS_DIR = src
OBJS_DIR = obj

SRCS = $(SRCS_DIR)/median_pb.c $(SRCS_DIR)/aux_1.c $(SRCS_DIR)/aux_2.c \
       $(SRCS_DIR)/main.c $(SRCS_DIR)/operations_1.c $(SRCS_DIR)/operations_2.c \
       $(SRCS_DIR)/operations_3.c $(SRCS_DIR)/parsing.c $(SRCS_DIR)/sorting_1.c \
       $(SRCS_DIR)/median_aux.c $(SRCS_DIR)/median_pa.c $(SRC_DIR)/big_chunks.c \
	   $(SRCS_DIR)/aux_4.c $(SRCS_DIR)/operations_4.c $(SRC_DIR)/aux_3.c \
	   $(SRCS_DIR)/sorting_2.c

OBJS = $(OBJS_DIR)/median_pb.o $(OBJS_DIR)/aux_1.o $(OBJS_DIR)/aux_2.o \
       $(OBJS_DIR)/main.o $(OBJS_DIR)/operations_1.o $(OBJS_DIR)/operations_2.o \
       $(OBJS_DIR)/operations_3.o $(OBJS_DIR)/parsing.o $(OBJS_DIR)/sorting_1.o \
       $(OBJS_DIR)/median_aux.o $(OBJS_DIR)/median_pa.o $(OBJS_DIR)/big_chunks.o \
	   $(OBJS_DIR)/aux_4.o $(OBJS_DIR)/operations_4.o $(OBJS_DIR)/aux_3.o \
	   $(OBJS_DIR)/sorting_2.o

LIBS_DIR = libs
LIBFT_PATH = $(LIBS_DIR)/Libft
LIBFT = libft.a

all: $(NAME)

$(LIBFT_PATH)/$(LIBFT):
	@make -C $(LIBFT_PATH) -s

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_PATH)/$(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/$(LIBFT) -o $(NAME)

clean:
	@make clean -C $(LIBFT_PATH) -s
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) -s

re: fclean all

.PHONY: all clean fclean re
