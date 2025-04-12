# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random_numbers.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 22:14:16 by migarrid          #+#    #+#              #
#    Updated: 2025/04/06 18:41:57 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys

# Obtener el valor mínimo y máximo de un entero
int_min = -2**31
int_max = 2**31-1

def main():
	# Obtener la cantidad de números desde el primer argumento de línea de comandos
	cantidad = int(sys.argv[1])
	# Generar 500 números aleatorios
	numeros_aleatorios = [random.randint(int_min, int_max) for _ in range(cantidad)]
	# Imprimir los números generados sin comas
	print(" ".join(map(str, numeros_aleatorios)))

main()
