# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random_numbers.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 22:14:16 by migarrid          #+#    #+#              #
#    Updated: 2025/03/18 22:26:23 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys

# Obtener el valor mínimo y máximo de un entero en Python
int_min = -2_147_483_648
int_max = 2_147_483_647

# Generar 500 números aleatorios
numeros_aleatorios = [random.randint(int_min, int_max) for _ in range(500)]

# Imprimir los números generados sin comas
print(" ".join(map(str, numeros_aleatorios)))
