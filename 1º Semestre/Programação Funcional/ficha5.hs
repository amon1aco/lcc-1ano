import Text.Html (yellow)
-- Ficha 5
{-
map:: (a->b) -> [a] -> [b]
map f [] = []
map f (x:xs) = (f x): map f xs


filter :: (a -> Bool) -> [a] -> [a]
filter f [] = []
filter f (x:xs)
    | f x = x : filter f xs
    | not (f x) = filter f xs


foldr :: (a->b->b) -> b -> [a] -> b
foldr f i [] = i
foldr f i (x:xs) = f x (foldr f i xs)
-}

--1
--a
algum :: (a -> Bool) -> [a] -> Bool
algum f [] = False 
algum f (x:y) | f x = True 
              | not $ f x = algum f y 

--b
zipacom :: (a->b->c) -> [a] -> [b] -> [c]
zipacom f (x:y) [] = []
zipacom f [] (a:b) = []
zipacom f [] [] = []
zipacom f (x:y) (a:b) = f x a : zipacom f y b

--c
takew :: (a->Bool) -> [a] -> [a]
takew f [] = []
takew f (x:y) | f x == True = x : takew f y
              | otherwise = []

--d
dropw :: (a->Bool) -> [a] -> [a]
dropw f [] = []
dropw f (x:y) | f x == True = dropw f y
              | f x == False = x:y

--e
spa :: (a -> Bool) -> [a] -> ([a],[a])
spa f [] = ([],[])
spa f (x:y) | not $ f x = ([],(x:y))
            | f x = (x:a,b)
        where (a,b) = spa f y
-- n percebi como funciona ali com uma lista vazia na linha 50

--f
deleteby :: (a -> a -> Bool) -> a -> [a] -> [a]
deleteby f x [] = []
deleteby f x (a:b) | f x a == True = b
                   | otherwise = a : deleteby f x b

--g
sorton :: Ord b => (a -> b) -> [a] -> [a]
sorton f [] = []
sorton f (a:b) = mete a (sorton f b)
     where mete x [] = [x]
           mete x (a:b) | f x <= f a = x : a : b
                        | otherwise = a : mete x b

--2

type Polinomio = [Monomio]
type Monomio = (Float,Int)

-- [(2,3), (3,4), (5,3), (4,5)]

--a
selgrau :: Int -> Polinomio -> Polinomio
selgrau x = filter (\(c,e) -> e == x)

--b
conta :: Int -> Polinomio -> Int
conta x l = sum (map (\(c,e)-> if e == x then 1 else 0) l)

--c
grau :: Polinomio -> Int
grau l = maximum (map snd l)

--d
deriv :: Polinomio -> Polinomio
deriv = map (\(c,e) -> if e >= 0 then (c * fromIntegral e, e - 1) else (0,0)) 

--e
calcula :: Float -> Polinomio -> Float
calcula x l = sum $ (map (\(c,e) -> x^e * c)) l

--f
simp :: Polinomio -> Polinomio
simp l = filter (\(c,e) -> e /= 0) l

--g
mult :: Monomio -> Polinomio -> Polinomio
mult (a,b) l = map (\(c,e) -> (a * c,b + e)) l

--h
ordena :: Polinomio -> Polinomio
ordena [] = []
ordena (a:b) = menores b  ++ [a] ++ maiores b
      where 
          menores b = filter (\x -> snd a <= snd x) b
          maiores b = filter (\x -> snd a > snd x) b

--i
normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza ((b,e):ps) = (sum [bs | (bs,es) <- selgrau e ps] + b,e):normaliza [(bo,eo) | (bo,eo) <- ps, eo /= e]
    --Nunca na vida chegava aqui 

--j
soma :: Polinomio -> Polinomio -> Polinomio
soma p1 p2 = normaliza $ p1 ++ p2

--k
produto :: Polinomio -> Polinomio -> Polinomio
produto p1 p2 = foldl (\a x -> soma (mult x p2) a) [] p1
    --Duvidas

--l
equiv :: Polinomio -> Polinomio -> Bool
equiv p1 p2 = null (simpa (soma p1 (mult (-1,0) p2)))

simpa :: Polinomio -> Polinomio
simpa l = filter (\(c,e) -> e /= 0 && c /= 0) l

--3
type Mat a = [[a]]

mat = [[1,2,3],[0,4,5],[0,0,6]]
mat1 = [[3,3,3],[3,4,5],[3,1,1]]

--a
dimok :: Mat a -> Bool 
dimok [] = True
dimok [c] = True 
dimok ((a:b):c) = if length (a:b) == length (head c) then dimok c else False 

--b
dimmat :: Mat a -> (Int, Int)
dimmat [] = (0,0)
dimmat ((a:b):c) = (length ((a:b):c),length (a:b))

--c
addmat :: Num a => Mat a -> Mat a -> Mat a
addmat = zipWith (zipWith (+))