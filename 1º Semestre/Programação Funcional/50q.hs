-- 50 questões

--1
enumfromto :: Int -> Int -> [Int]
enumfromto x y | x < y = x : enumfromto (x+1) y
               | x == y = [x]

--2
enumfromthento :: Int -> Int -> Int -> [Int]
enumfromthento x y z | x < z = x : enumfromthento (x+(abs(y-x))) (y+(abs(y-x))) z
                     | x > z = []
                     | x == z = [x]
        
--3
pp :: [a] -> [a] -> [a]
pp l [] = l
pp [] l = l
pp (x:y) l = x : pp y l

--4
ee :: [a] -> Int -> a
ee (x:y) 0 = x
ee (x:y) p = ee y (p-1)

--5
reversa :: [a] -> [a]
reversa [] = []
reversa (x:y) = reversa y ++ [x]

--6
takem :: Int -> [a] -> [a]
takem x [] = []
takem 0 l = []
takem x (a:b) = a : takem (x-1) b
    
--7
dropa :: Int -> [a] -> [a]
dropa _ [] = []
dropa 0 l = l 
dropa x (a:b) = dropa (x-1) b

--8
zipa :: [a] -> [b] -> [(a,b)]
zipa l [] = []
zipa [] l = []
zipa (a:b) (x:y) = (a,x) : zipa b y

--9
replica :: Int -> a -> [a]
replica 0 x = []
replica x y = y : replica (x-1) y

--10
interspace :: a -> [a] -> [a]
interspace x [a] = [a]
interspace x (a:b) = a : x : interspace x b

--11
agrupa :: Eq a => [a] -> [[a]]
agrupa [] = [[]]
        -- Por Fazer!!!!

--12
concata :: [[a]] -> [a]
concata [] = []
concata (a:b) = a ++ concata b

--13
initss :: [a] -> [[a]]
initss [] = [[]]
initss l = initss (init l) ++ [l]

--14
tailss :: [a] -> [[a]]
tailss [] = [[]]
tailss l = [l] ++ tailss (removehead l)

removehead :: [a] -> [a]
removehead [] = []
removehead (a:b) = b

--15
heads :: [[a]] -> [a]
heads [] = []
heads ([]:z) = heads z
heads ((a:b):c) = a : heads c

--16
comprimento :: [a] -> Int 
comprimento [] = 0
comprimento (x:y) = 1 + comprimento y

total :: [[a]] -> Int 
total [[]] = 0 
total ((a:b):c) = comprimento (a:b) + total c

--17
fun :: [(a,b,c)] -> [(a,c)]
fun [] = []
fun ((a,b,c):d) = (a,c) : fun d

--18
cola :: [(String,b,c)] -> String 
cola [] = []
cola ((a,b,c):d) = a ++ cola d

--19
idade :: Int -> Int -> [(String, Int)] -> [String]
        -- idade 2021 26 [("rui",1995), ("maria",2009), ("ana",1947)]
idade _ _ [] = []
idade x y ((a,b):c) | abs (b - x) >= y = a : idade x y c
                    | otherwise = idade x y c

--20
powerenumfrom :: Int -> Int -> [Int]
powerenumfrom n m = [n^x | x <- [0..(m-1)]]

--21
isprime :: Int -> Bool 
isprime x = length [m | m <- [2..x], x `mod` m == 0] == 1
        -- Não usa o "sqrt" porque estava a dar erro de tipo e nem com o "isqrt" resolvia..

--22
isprefixof :: Eq a => [a] -> [a] -> Bool
isprefixof [] l = True
isprefixof l [] = False
isprefixof (a:b) (x:y) | a == x = isprefixof b y
                       | otherwise = False

--23
issufixof :: Eq a => [a] -> [a] -> Bool
issufixof a b = isprefixof (reverse a) (reverse b)

--24
sequencia :: Eq a => [a] -> [a] -> Bool
sequencia [] _ = True
sequencia _ [] = False
sequencia (a:b) (x:y) | a == x = sequencia b y
                      | otherwise = sequencia (a:b) y

--25
elemindices :: Eq a => a -> [a] -> [Int]
elemindices _ [] = []
elemindices x l = posicao x 0 l

posicao :: Eq a => a -> Int -> [a] -> [Int]
posicao x y [] = []
posicao x y (a:b) | x == a = y : posicao x (y+1) b
                  | otherwise = posicao x (y+1) b

--26
nub :: Eq a => [a] -> [a] 
nub [] = []
nub (a:b) | a `elem` b = nub b
          | not $ a `elem` b = a : nub b

--27
delete :: Eq a => a -> [a] -> [a]
delete _ [] = []
delete x (a:b) | x == a = b
               | otherwise = a : delete x b

--28
bb :: Eq a => [a] -> [a] -> [a]
bb l1 [] = l1
bb [] l2 = []
bb (a:b) (x:y) = bb (delete x (a:b)) y

--29
union :: Eq a => [a] -> [a] -> [a]
union [] l = l
union l [] = l
union (a:b) (x:y) | x `elem` (a:b) = union (a:b) y
                  | otherwise = union (a:b) y ++ [x]

--30
intersect :: Eq a => [a] -> [a] -> [a]
intersect [] l = []
intersect l [] = []
intersect (a:b) (x:y) | x `elem` (a:b) = x : intersect (a:b) y
                      | otherwise = intersect (a:b) y

--31
insert :: Ord a => a -> [a] -> [a]
insert x [] = [x]
insert x (a:b) | x > a = a : insert x b
               | otherwise = x : a : b

--32
unwordes :: [String] -> String 
unwordes [] = ""
unwordes [a] = a
unwordes (a:b) = a ++ " " ++ unwordes b

--33
unlins :: [String] -> String 
unlins [] = "\n"
unlins [a] = a ++ "\n"
unlins (a:b) = a ++ "\n" ++ unwordes b

--34
pmaior :: Ord a => [a] -> Int 
pmaior [] = 0
pmaior (x:y) = seg $ maior (x:y) (x,0,0)


maior :: Ord a => [a] -> (a,Int,Int) -> (a,Int,Int)
maior [] (a,b,c) = (a,b,c)
maior (x:y) (a,b,c) | a >= x = maior y (a,b,c+1)
                    | a < x = maior y (x,c,c+1)

seg :: (a,Int,Int) -> Int 
seg (a,b,c) = b

--35
lokup :: Eq a => a -> [(a,b)] -> Maybe b
lokup _ [] = Nothing 
lokup x ((a,b):c) | x == a = Just b
                  | otherwise = lokup x c

--36
precrescente :: Ord a => [a] -> [a] 
precrescente [] = []
precrescente (a:b) | a < head b = a : precrescente b
                   | otherwise = [a]

--37
isort :: Ord a => [a] -> [a]
isort l = foldr insert [] l

--38
menor :: String -> String -> Bool 
menor (a:b) (x:y) | a < x = True 
                  | a == x = menor b y
                  | otherwise = False

--39
elemset :: Eq a => a -> [(a,Int)] -> Bool
elemset x [] = False 
elemset x ((a,b):c) | x == a = True 
                    | otherwise = elemset x c

--40
convertmset :: [(a,Int)] -> [a]
convertmset [] = []
convertmset ((a,b):c) | b /= 0 = [a] ++ convertmset ((a,(b-1)):c)
                      | b == 0 = convertmset c
          
--41
insermset :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insermset x [] = [(x,1)]
insermset x ((a,b):c) | x == a = (a,b+1):c
                      | otherwise = (a,b) : insermset x c

--42
removemset :: Eq a => a -> [(a,Int)] -> [(a,Int)]
removemset x [] = []
removemset x ((a,b):c) | x == a = c
                       | otherwise = (a,b) : removemset x c

--43
constroimset :: Ord a => [a] -> [(a,Int)]
constroimset [] = []
constroimset (a:b) = reverse $ insermset a (constroimset b)

--44
partitioneithers :: [Either a b] -> ([a],[b])
partitioneithers [] =  ([],[])
partitioneithers (a:b) = case a of 
                              Left n -> (n:x,y)
                              Right n -> (x, n:y)
                where (x,y) = partitioneithers b

--45
catmaybes :: [Maybe a] -> [a]
catmaybes [] = []
catmaybes (a:b) = case a of 
                        Nothing -> catmaybes b
                        Just n -> n : catmaybes b

--46
data Movimento = Norte | Sul | Este | Oeste
        deriving Show

caminho :: (Int,Int) -> (Int,Int) -> [Movimento]
caminho (x,y) (a,b) | x < a = Este : caminho (x+1,y) (a,b)
                    | x > a = Oeste : caminho (x-1,y) (a,b)
                    | y < b = Norte : caminho (x,y+1) (a,b)
                    | y > b = Sul : caminho (x,y-1) (a,b)
                    | x == a && y == b = []
                
--47
posicao1 :: (Int,Int) -> [Movimento] -> (Int,Int)
posicao1 (x,y) [] = (x,y)
posicao1 (x,y) (a:b) = case a of 
                              Norte -> posicao1 (x,y+1) b
                              Sul   -> posicao1 (x,y-1) b
                              Este  -> posicao1 (x+1,y) b
                              Oeste -> posicao1 (x-1,y) b

hasloops :: (Int,Int) -> [Movimento] -> Bool
hasloops (_,_) [] = False 
hasloops (a,b) (x:y) | (a,b) == posicao1 (a,b) (x:y) = True
                     | otherwise = hasloops (a,b) (init (x:y))

--48
type Ponto = (Float,Float)
data Rectangulo = Rect Ponto Ponto

ex = [Rect (1,2) (2,3), Rect (1,5) (2,1)]

contaquadrados :: [Rectangulo] -> Int 
contaquadrados [] = 0
contaquadrados (Rect (x,y) (z,w):b) | abs (z-x) == abs (w-y) = 1 + contaquadrados b
                                    | otherwise = contaquadrados b

--49
areatotal :: [Rectangulo] -> Float
areatotal [] = 0
areatotal (Rect (x,y) (z,w):b) = abs  $ (z-x) * (w-y) + areatotal b

--50
data Equipamento = Bom | Avariado | Razoavel
        deriving Show

naoreparar :: [Equipamento] -> Int
naoreparar [] = 0
naoreparar (a:b) = case a of 
                          Bom -> 1 + naoreparar b 
                          Razoavel -> 1 + naoreparar b 
                          Avariado -> naoreparar b
