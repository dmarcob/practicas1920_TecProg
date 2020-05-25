module Turtle where

type Position = (Float,Float)
type Heading  = Float
type Turtle   = (Float,Float,Position,Heading)

data Move     = Forward | TurnLeft | TurnRight

moveTurtle :: Turtle -> Move -> Turtle
moveTurtle (d,a,(x,y),t) Forward   = (d,a,(x+d*(cos trad),y+d*(sin trad)),t)
  where
    trad = (pi/180.0)*t
moveTurtle (d,a,(x,y),t) TurnLeft  = (d,a,(x,y),t-a)
moveTurtle (d,a,(x,y),t) TurnRight = (d,a,(x,y),t+a)
