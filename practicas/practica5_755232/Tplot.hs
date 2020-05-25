------------------------------------------------------------------
--Autor: Diego Marco, 755232
--Fichero: Tplot.hs
--Fecha: 25-05-2020
--Coms: Parte 1, práctica 5. Gráficos de Tortuga, función tplot.
------------------------------------------------------------------
module Tplot where

import Turtle

tercer :: (a, b, c, d) -> c

-- Devuelve tercer elemento de una tupla
tercer (_,_,x,_) = x


tplot :: Turtle -> String -> [Position]

-- Match con último comando de la lista
tplot estado (x:[])
    -- Caso > ó mayuscula := avanzar la tortuga
    | x == '>' || (x>='A' && x<='Z') =  [tercer estado] ++ [tercer $ moveTurtle estado Forward]
    -- Caso es minúscula ó + ó - := Ningún efecto. Devuelve la última posición registrada de la tortuga.
    | otherwise = [tercer estado]

-- Match con comandos que no estan en la ultima posicion de la lista
tplot estado (x:tail) 
    -- Caso > ó mayuscula := avanzar la tortuga
    | x == '>' || (x>='A' && x<='Z') = [tercer estado] ++ tplot (moveTurtle estado Forward) tail
    -- Caso + := Girar la tortuga a la derecha
    | x == '+' = tplot (moveTurtle estado TurnRight) tail
    -- Caso - := Girar la tortuga a la izquierda
    | x == '-' = tplot (moveTurtle estado TurnLeft) tail
    -- Caso es minuscula := Ningun efecto. Se invoca recursivamente al siguiente comando de la lista
    | otherwise = tplot estado tail
