# settings
NAME     = hotrace
SRC      = \
	./utils.c \
	./handle_add_value.c \
	./main.c \
	./readline_stdin.c \
	./handle_get_node.c \
	./calc_start_index.c \
	./hash.c \
	./create_hashmap.c \
	./extend_hashmap.c \
	./free_hashmap.c \
	./init_hashmap.c \
	./add_hashnode.c \
	./assign_hashnode.c \
	./create_hashnode.c \
	./free_hashnode.c \
	./get_hashnode.c \
	./is_empty_hashnode.c \
	./next_hashnode.c \
	./create_hashnode_list.c \
	./free_hashnode_list.c \
	./hmap_add_value.c \
	./hmap_destroy_hashmap.c \
	./hmap_get_node.c \
	./hmap_new_hashmap.c \
	./is_equal_hotstring.c \
	./print_hotstring.c \
	./ft_calloc.c \
	./ft_memset.c \
	./ft_putstr_fd.c \
	./ft_strequal.c

CC      = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I include
CACHEDIR = cache

# generate from above variable
OBJS    = $(addprefix $(CACHEDIR)/,$(SRC:.c=.o))
DEPS    = $(addprefix $(CACHEDIR)/,$(SRC:.c=.d))

# PHONY rules
all: $(NAME)

clean:
	rm -rf $(CACHEDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: LDFLAGS += -g -O0
debug: CFLAGS += -g -O0
debug: all

-include $(DEPS)

# file rules
$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

$(CACHEDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MF $(CACHEDIR)/$*.d -o $@ -c $<
