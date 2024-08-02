NAME = push_swap
all :
	@make -C ./mandatory
	@make -C ./Bonus

mandatory :
	@make -C ./mandatory

Bonus :
	@make -C ./Bonus

clean :
	@make clean -C ./mandatory
	@make clean -C ./Bonus

fclean :
	@make fclean -C ./mandatory
	@make fclean -C ./Bonus

re : fclean all

.PHONY : all mandatory Bonus clean fclean re
