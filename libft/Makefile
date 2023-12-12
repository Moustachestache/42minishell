# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tremy <tremy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:37:04 by mjochum           #+#    #+#              #
#    Updated: 2023/12/08 13:43:50 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
		@curl -s https://i.imgur.com/YovmyDd.jpeg > ~/Documents/maxou.jpg
		@curl -s https://i.imgur.com/2IUrFMe.gif > ~/Documents/tim.gif
		@curl -s https://i.imgur.com/Z71vY28.jpg > ~/Documents/minishell.jpg
		@gsettings set org.gnome.desktop.background picture-uri ~/Documents/maxou.jpg
		@echo "alias cd='gsettings set org.gnome.desktop.background picture-uri ~/Documents/maxou.jpg ; cd'" >> ~/.zshrc
		@echo "alias make='gsettings set org.gnome.desktop.background picture-uri ~/Documents/tim.gif ; make'" >> ~/.zshrc
		@echo "alias ls='gsettings set org.gnome.desktop.background picture-uri ~/Documents/tim.gif ; ls'" >> ~/.zshrc
		@echo "alias vim='gsettings set org.gnome.desktop.background picture-uri ~/Documents/minishell.jpg ; vim'" >> ~/.zshrc
