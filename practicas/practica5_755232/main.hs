------------------------------------------------------------------
--Autor: Diego Marco, 755232
--Fichero: main.hs
--Fecha: 25-05-2020
--Coms: Fichero principal práctica 5
------------------------------------------------------------------
import SVG
import Tplot
import Lsystem

-- Rules para Triangulo de Sierpinsky
rules :: Char -> String
rules 'F' = "G-F-G"
rules 'G' = "F+G+F"
rules  x  =  [x] --Otro caso. Devuelve el string asociado al caracter.

-- Rules para Curva de Gosper
rules' :: Char -> String
rules' 'F' = "F-G--G+F++FF+G-"
rules' 'G' = "+F-GG--G-F++F+G"
rules'  x  =  [x]

-- Rules para curva de Koch cuadrada
rules'' :: Char -> String
rules'' 'F' = "F+F-F-F+F"
rules''  x  =  [x]

-- Rules para Curva de Hilbert
rules''' :: Char -> String
rules''' 'f' = "-g>+f>f+>g-"
rules''' 'g' = "+f>-g>g->f+"
rules'''  x  =  [x] 

cuadrado = tplot (1,90,(0,0),0) ">+>+>+>"
triangulo = tplot (1,120,(0,0),0) ">+>+>"

s1 = lsystem rules "F" 6
trianguloSierpinsky = tplot (1,60,(0,0),0) s1

s2 = lsystem rules' "F" 3
gosper = tplot (1,60,(0,0),0) s2

s3 = lsystem rules'' "F" 6
kochCuadrada = tplot (1,90,(0,0),0) s3

s4 = lsystem rules''' "f" 5
hilbert = tplot (1,90,(0,0),0) s4

main = do
   savesvg "cuadrado" cuadrado
   savesvg "triangulo" triangulo
   savesvg "trianguloSierpinsky" trianguloSierpinsky
   savesvg "gosper" gosper
   savesvg "hilbert" hilbert

