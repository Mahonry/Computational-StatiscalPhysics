# Computational Statiscal Physics

## [Caminantes Aleatorios](https://en.wikipedia.org/wiki/Random_walk)

Lo primero que simulamos es un caminante aleatorio en una dimension donde la densidad de probabilidad esta dada por la ecuación.

$$\frac{\partial \Psi}{\partial t} = \frac{1}{2}C\frac{\partial^2\Psi}{\partial x^2}$$

Donde C es la constante de difusion.

La solucion a esta ecuación es lo que conocemos como **Ecuación de Difusión**:

$$\Psi(x,t) = \frac{1}{\sqrt{2 \pi ct}}e^{\frac{-x^2}{2ct}}$$

Los codigos de esta simulacion son:

- [Random_Walk](https://github.com/Mahonry/StatiscalPhysics/blob/main/Random_Walk.cpp): Simula un caminante aleatorio en un una dimension, basado en un número aletorio de una distribución gaussiana, regresa un archivo con las posiciones del caminante en X.

- [Random_Walk_Ensemble](https://github.com/Mahonry/StatiscalPhysics/blob/main/Random_Walk_Ensemble.cpp): Simula un ensamble de caminantes aleatorios en un una dimension, basados en un número aletorio de una distribución gaussiana, regresa un archivos con las posiciones X en el ensamble al tiempo t.

## [Cadenas de Markov](https://es.wikipedia.org/wiki/Cadena_de_M%C3%A1rkov)

Para un proceso Markoviano el sistema evolucion con una ecuación maestra de la forma:

$$P_{ij}(t+1) = \sum_{l = 1}^NP_{il}(t)W_{l \rightarrow j}$$

O escrita en forma matricial:

$$\vec{P}(t+1) = \vec{P}(t)\widehat{W}$$

$$\vec{P}(t) = \vec{P}(0)\widehat{W}^t$$

El proceso markoviano simulado es uno de dos estados representado por la siguiente cadena:

<p align="center">
  <img src="./images/Markov Chain Two States.png"
       width = "200"> 
</p>

Para el sistma la matriz de transición se escribe como:

$$\widehat{W} = 
    \begin{bmatrix}
    1-P & P \\
    q & 1-q
    \end{bmatrix}
$$


El proceso simulado tiene solución analítica para los tiempos medios de primer paso $\langle T_{ij} \rangle$, los cuales estan dados por:

$$
    \langle T_{ij} \rangle = 
    \begin{bmatrix}
    \langle T_{0 \rightarrow 0} \rangle & \langle T_{0 \rightarrow 1} \rangle \\
    \langle T_{1 \rightarrow 0} \rangle & \langle T_{1 \rightarrow 1} \rangle
    \end{bmatrix} 
$$

$$
    \langle T_{ij} \rangle = 
    \begin{bmatrix}
    \frac{P + q}{q}  & \frac{1}{P} \\
    \frac{1}{q} & \frac{P + q}{q}
    \end{bmatrix}

$$

Para simular este proceso, los códigos son:

- [FST_first_step_time](https://github.com/Mahonry/StatiscalPhysics/blob/main/FST_first_step_time.cpp): Barre las probabilidades de **P** desde 0.01 hasta 0.5, nos devuelve un archivo que contiene la probabilidad y los tiempos de primer paso, es decir, los tiempos de pasar del estado 0 al estado 1 para cada una de las probabilidades. Con base en estos resultados podemos calcular el tiempo medio de primer paso.

- [FRT_first_return_time](https://github.com/Mahonry/StatiscalPhysics/blob/main/FRT_first_return_time.cpp): Barre las probabilidades de **P** desde 0.01 hasta 0.5, nos devuelve un archivo que contiene la probabilidad y los tiempos de primer restorn, es decir, los tiempos de pasar del estado 0 y regresar al estado 0 para cada una de las probabilidades. Con base en estos resultados podemos calcular el tiempo medio de primer retorno.

- [Two_level_FST](https://github.com/Mahonry/StatiscalPhysics/blob/main/Two_Level_FST.cpp): Incorpora y simplifica los dos códigos anteriores, donde el parametro target nos indica el proceso a calcular (ya sea primer paso o retorno).