# Computational Statiscal Physics (Monte Carlo Simulations) 

# Random Walkers (Caminantes Aleatorios)

Lo primero que simulamos es un caminante aleatorio en una dimension donde la densidad de probabilidad esta dada por la ecuación.

$$\frac{\partial \Psi}{\partial t} = \frac{1}{2}C\frac{\partial^2\Psi}{\partial x^2}$$

Donde C es la constante de difusion.

La solucion a esta ecuación es lo que conocemos como **Ecuación de Difusión**:

$$\Psi(x,t) = \frac{1}{\sqrt{2 \pi ct}}e^{\frac{-x^2}{2ct}}$$

Los codigos de esta simulacion son:

- [Random_Walk](https://github.com/Mahonry/StatiscalPhysics/blob/main/Random_Walk.cpp): Simula un caminante aleatorio en un una dimension, basado en un número aletorio de una distribución gaussiana, regresa un archivo con las posiciones del caminante en X.

- [Random_Walk_Ensemble](https://github.com/Mahonry/StatiscalPhysics/blob/main/Random_Walk_Ensemble.cpp): Simula un ensamble de caminantes aleatorios en un una dimension, basados en un número aletorio de una distribución gaussiana, regresa un archivos con las posiciones X en el ensamble al tiempo t.

# Cadenas de Markov

Para un proceso Markoviano el sistema evolucion con una ecuación maestra de la forma:

$$P_{ij}(t+1) = \sum_{l = 1}^NP_{il}(t)W_{l \rightarrow j}$$

O escrita en forma matricial:

$$\vec{P}(t+1) = \vec{P}(t)\widehat{W}$$
$$\vec{P}(t)v = \vec{P}(0)\widehat{W}^t$$

El proceso markoviano simulado es uno de dos estados representado por la siguiente cadena: