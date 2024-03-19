# import subprocess
# import random

# INT_MIN = -1000000  # La valeur minimale d'un int en C
# INT_MAX = 1000000   # La valeur maximale d'un int en C
# NUM_NUMBERS = 3000     # Nombre de nombres aléatoires à générer

# # Générer une liste de nombres aléatoires
# random_numbers = [random.randint(INT_MIN, INT_MAX) for _ in range(NUM_NUMBERS)]

# # Convertir la liste de nombres en une chaîne de caractères
# arguments = ' '.join(map(str, random_numbers))

# # Appeler le programme avec les arguments
# subprocess.run(['./PmergeMe'] + arguments.split())


import random
import subprocess

INT_MIN = 0  # La valeur minimale d'un int en C
INT_MAX = 4294967295  # La valeur maximale d'un int en C
NUM_NUMBERS = 5000  # Nombre de nombres aléatoires à générer

# Liste pour stocker les nombres choisis
selected_numbers = []

# Exécuter la boucle pour choisir 3000 nombres arbitraires
for _ in range(3000):
    # Générer une liste de nombres aléatoires
    random_numbers = [random.randint(INT_MIN, INT_MAX)
                      for _ in range(NUM_NUMBERS)]

    # Choisir un nombre aléatoire parmi la liste de nombres générés
    selected_number = random.choice(random_numbers)

    # Ajouter le nombre choisi à la liste
    selected_numbers.append(selected_number)

# Afficher la liste de 3000 nombres choisis arbitrairement
# print(selected_numbers)

# Afficher le plus petit et le plus grand
print("Le plus petit nombre est : ", min(selected_numbers))
print("Le plus grand nombre est : ", max(selected_numbers))

# Utiliser la list comme argument pour le programme
arguments = ' '.join(map(str, selected_numbers))

# Appeler le programme avec les arguments
subprocess.run(['./PmergeMe'] + arguments.split())
