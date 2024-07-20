import Data.Char
-- Ficha 1 

-- 1

--a
perimetro :: Double -> Double
perimetro r = 2 * r * (3.1416) 

--b
dist :: (Double, Double) -> (Double, Double) -> Double 
dist (x,y) (a,b) = sqrt (((x-a)^2) + ((y-b)^2))

--c
primult :: [Int] -> (Int,Int)
primult (x:y) = (x, last y)

--d
multiplo :: Int -> Int -> Bool 
multiplo x y | mod x y == 0 = True 
             | otherwise = False 

--e
truncaimpar :: [Int] -> [Int]
truncaimpar (x:y) | length (x:y) `mod` 2 == 0 = (x:y)
                  | otherwise = y

--f
max2 :: Int -> Int -> Int 
max2 x y | x > y = x
         | otherwise = y

--g
max3 :: Int -> Int -> Int -> Int
max3 x y z | x > y `max2` z = x
           | otherwise = max2 y z

--2
--a
nraizes :: Double -> Double -> Double -> Int
nraizes a b c | (b*b) - (4*a*c) > 0 = 2  
              | (b*b - 4*a*c) == 0 = 1
              | (b*b - 4*a*c) < 0 = 0

--b
raizes :: Double -> Double -> Double -> [Double]
raizes a b c | nraizes a b c == 0 = []
             | nraizes a b c == 1 = [x]
             | nraizes a b c == 2 = [x,y]
    where (x,y) = (((-b) + sqrt (b^2 - 4*a*c)) / (2*a) , ((-b) - sqrt (b^2 - 4*a*c)) / (2*a) )   

--3
type Hora = (Int,Int)

--a
valida :: Hora -> Bool
valida (a,b) = if a >= 0 && a < 24 && b >= 0 && b <= 59 then True else False

--b
compara :: Hora -> Hora -> Bool
compara (a,b) (d,e) | a > d = True
                    | a == d && b > e = True
                    | otherwise = False

--c
minutos :: Hora -> Int
minutos (a,b) = b + (60*a)

--d
horas :: Int -> Hora 
horas x = (x `div` 60, mod x 60)

--e
diff :: Hora -> Hora -> Int
diff (a,b) (c,d) = minutos (abs (a-c),abs (b-d))

--f
addmin :: Int -> Hora -> Hora
addmin x (a,b) = somah (horas x) (a,b)
  where somah :: Hora -> Hora -> Hora
        somah (a,b) (c,d) = (a+c,b+d)

--4
data Hour = H Int Int 
    deriving (Show,Eq)

--a
valida1 :: Hour -> Bool
valida1 (H a b) = if a >= 0 && a < 24 && b >= 0 && b <= 59 then True else False

--b
compara1 :: Hour -> Hour -> Bool
compara1 (H a b)(H c d) | a > c = True
                        | a == c && b > d = True
                        | otherwise = False

--c
minutos1 :: Hour -> Int
minutos1 (H a b) = b + (60*a)

--d
horas1 :: Int -> Hour 
horas1 x = (H (x `div` 60) (mod x 60))

--e
diff1 :: Hour -> Hour -> Int
diff1 (H a b) (H c d) = minutos1 (H (abs (a-c))(abs (b-d)))

--d
addmin1 :: Int -> Hour -> Hour
addmin1 x (H a b) = somah (horas1 x) (H a b)
  where somah :: Hour -> Hour -> Hour
        somah (H a b) (H c d) = (H (a+c)(b+d))

--5
data Semaforo = Verde | Amarelo | Vermelho  
    deriving (Show,Eq)

--a
next :: Semaforo -> Semaforo
next a = case a of 
            Verde -> Amarelo
            Amarelo -> Vermelho
            Vermelho -> Verde

--b
stop :: Semaforo -> Bool 
stop a = case a of 
              Verde -> False 
              _ -> True

--c
safe :: Semaforo -> Semaforo -> Bool 
safe a b = if a == Verde && b == Verde then False else True
 
--6 

data Ponto = Cartesiano Double Double | Polar Double Double
    deriving (Show,Eq)

p1 = Cartesiano 3 4
p2 = Polar 4 30


aux :: Ponto -> Ponto
aux (Polar x y) = Cartesiano a b
     where a = (cos y) * x
           b = (sin y) * x

--a
posx :: Ponto -> Double
posx (Polar x y) = let
    (Cartesiano x y) = aux (Polar x y)
    in if x < 0 then (-x) else x
posx (Cartesiano x y) = if x < 0 then (-x) else x 
    -- Não dá o p2, mas penso q é bug..

--b
posy :: Ponto -> Double 
posy (Polar x y) = let
    (Cartesiano x y) = aux (Polar x y)
    in if y < 0 then (-y) else y
posy (Cartesiano x y) = if y < 0 then (-y) else y 
   -- Não dá o p2 novamente e continuo a pensar que é bug..

--c
raio :: Ponto -> Double 
raio (Cartesiano x y) = dist (x,y) (0,0)
raio (Polar x y) = x

--d
angulo :: Ponto -> Double 
angulo (Polar x y) = y
angulo (Cartesiano x y) = atan (y/x)

--e 
dist2 :: Ponto -> Ponto -> Double 
dist2 (Cartesiano x y) (Cartesiano a b) = dist (x,y) (a,b)
dist2 (Cartesiano x y) (Polar a b) = dist (x,y) (a * cos b, a * sin b)
dist2 (Polar x y) (Cartesiano a b) = dist (x * cos y, x * sin y) (a,b)
dist2 (Polar x y) (Polar a b) = dist (x * cos y, x * sin y) (a * cos b, a * sin b)
        -- pede uma função show / print??

--7 
data Figura = Circulo Ponto Double 
            | Retangulo Ponto Ponto
            | Triangulo Ponto Ponto Ponto
        deriving (Show,Eq)

fig1 = Circulo (Cartesiano 3 4) 3 
fig2 = Retangulo (Cartesiano 3 5) (Cartesiano 2 4)
fig3 = Triangulo (Cartesiano 2 3) (Cartesiano 5 4) (Cartesiano 4 2)

--a
poligno :: Figura -> Bool 
poligno (Circulo _ _) = False 
poligno otherwise = True

--b
vertices :: Figura -> [Ponto]
vertices (Circulo _ _) = []
vertices (Retangulo x y) = [x] ++ [y]
vertices (Triangulo x y z) = [x] ++ [y] ++ [z]

--c
area :: Figura -> Double 
area (Triangulo p1 p2 p3) = 
    let a = dist2 p1 p2
        b = dist2 p2 p3
        c = dist2 p3 p1
        s = (a+b+c) / 2 -- semi perimetro
    in sqrt (a*(s-a)*(s-b)*(s-c)) -- formula de heron
area (Circulo x y) = 3.1416 * y^2
area (Retangulo (Cartesiano x y)(Cartesiano a b)) | (x-a) * (y-b) < 0 = -((x-a) * (y-b))
                                                  | otherwise = (x-a) * (y-b)

--d
perimetro2 :: Figura -> Double 
perimetro2 (Circulo x y) = 2 * y * 3.1416
perimetro2 (Triangulo x y z) = dist2 x y + dist2 y z + dist2 z x
perimetro2 (Retangulo (Cartesiano x y)(Cartesiano a b)) | (x-a) * 2 + (y-b) * 2  > 0 = (x-a) * 2 + (y-b) * 2  
                                                       | otherwise = - ((x-a) * 2 + (y-b) * 2)


--8
--a
isMinuscula :: Char -> Bool
isMinuscula x = x `elem` ['a'..'z']

--b
isDigito :: Char -> Bool 
isDigito x = ord x >= ord '0' && ord x <= ord '9'

--c
isLetra :: Char -> Bool 
isLetra x = x `elem` ['a'..'z'] || x `elem` ['A'..'Z']

--d
toUp :: Char -> Char 
toUp x = if isLower x then chr (ord x - 32) else x

--e
int2digito :: Int -> Char 
int2digito x = chr (x+48)

--f
digit2int :: Char -> Int 
digit2int x = ord x - 48

