# 🧠 Push Swap — 42 Project

`push_swap` es un proyecto de 42 que consiste en ordenar una pila de números utilizando un conjunto limitado de operaciones y con el menor número de movimientos posible. Este proyecto pone a prueba tus habilidades en algoritmia, optimización y manipulación de estructuras como pilas y listas. ⚙️

---

## 🧩 Objetivo

Dado un conjunto de números desordenados en una pila (`stack_a`), el objetivo es ordenarlos utilizando un segundo stack (`stack_b`) y un conjunto muy limitado de instrucciones. El reto está en **minimizar el número de operaciones**.

---

## 🔧 Operaciones permitidas

- **swap**: `sa`, `sb`, `ss`
- **push**: `pa`, `pb`
- **rotate**: `ra`, `rb`, `rr`
- **reverse rotate**: `rra`, `rrb`, `rrr`

Estas operaciones afectan a una o ambas pilas. ¡No se permite usar funciones de ordenación del sistema!

---

## 🧠 Algoritmo aplicado

Inspirado en el enfoque del artículo [“Push Swap” by Ayogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), el algoritmo sigue una estrategia basada en **coste mínimo de movimientos**:

### 🔄 Etapas principales

1. **Indexado**: Asigno un índice a cada número basado en su orden en la lista ordenada.
2. **Reducir el stack_a**: Dejo el `stack_a` completmente vacío y paso todos los números con el movimiento `pushb` al `stack_b`.
3. **Reinserción desde stack_b**:
   - Por cada número en `stack_b`, calculo el coste de insertarlo correctamente en `stack_a`.
   - Aplico la rotación óptima combinada para minimizar movimientos (`rr`, `rrr`, etc.).
4. **Rotar stack_a** para que el valor mínimo esté en la cima.

Esta estrategia permite reducir significativamente el número de operaciones necesarias, sobre todo para listas grandes.

---

## 🧪 Cómo usar

```bash
make
./push_swap "3 2 1 6 5 4"
