module SVG(savesvg) where

import Text.Printf

polyline :: [(Float, Float)] -> String
polyline vertices =
    "<svg xmlns=\"http://www.w3.org/2000/svg\"\n"
    ++ " viewBox=\""
    ++ printf "%10.6f %10.6f" minx miny
    ++ " "
    ++ printf "%10.6f %10.6f" sx sy
    ++ "\"\n"
    ++ ">\n"
    ++ "<polyline\n"
    ++ " fill=\"none\" stroke=\"green\" stroke-width=\"" ++ show w++ "\"\n"
    ++ " points=\"\n"
    ++ (concat $ map (\(x,y) -> printf "%10.6f,%10.6f\n" x y) vertices)
    ++ " \"\n"
    ++ "/>\n"
    ++ "</svg>\n"
    where
--        x = map fst vertices
--        y = map snd vertices
--        minx = minimum x
--        miny = minimum y
--        maxx = maximum x
--        maxy = maximum y
        (minx,miny) = foldl1 (\(mx,my) (x,y) -> (min mx x,min my y)) vertices
        (maxx,maxy) = foldl1 (\(mx,my) (x,y) -> (max mx x,max my y)) vertices
        sx = if minx /= maxx then 1.1*(maxx - minx) else 1.0
        sy = if miny /= maxy then 1.1*(maxy - miny) else 1.0
        w = 0.002 * (max sx sy)

savesvg name pts = writeFile (name++".svg") (polyline pts)
