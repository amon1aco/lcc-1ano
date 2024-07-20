import Distribution.Simple.Utils (xargs)
-- Ficha 7
--1
data ExpInt = Const Int 
            | Simetrico ExpInt
            | Mais ExpInt ExpInt
            | Menos ExpInt ExpInt
            | Mult ExpInt ExpInt
  --  deriving show (ExpInt)

arv = (Mais (Const 3)(Menos (Const 3) (Const 5)))

--a
calcula :: ExpInt -> Int 
calcula (Const a) = a 
calcula (Simetrico a) = (- calcula a)
calcula (Mais a b) = calcula a + calcula b
calcula (Menos a b) = calcula a - calcula b
calcula (Mult a b) = calcula a * calcula b

--b
infixa :: ExpInt -> String 
infixa (Const a) = show a 
infixa (Simetrico a) = "(" ++ "-" ++ infixa a ++ ")"
infixa (Mais a b) = "(" ++ infixa a ++ "+" ++ infixa b ++ ")"
infixa (Menos a b) = "(" ++ infixa a ++ "-" ++ infixa b ++ ")"
infixa (Mult a b) = "(" ++ infixa a ++ "x" ++ infixa b ++ ")"

--c
posfixa :: ExpInt -> String 
posfixa (Const a) = show a 
posfixa (Simetrico a) = "- " ++ posfixa a 
posfixa (Mais a b) = posfixa a ++ " " ++ posfixa b ++ " " ++ "+"
posfixa (Menos a b) = posfixa a ++ " " ++ posfixa b ++ " " ++ "-"
posfixa (Mult a b) = posfixa a ++ " " ++ posfixa b ++ " " ++ "x"

--2
data RTree a = R a [RTree a]
  deriving Show 
rt = R 3 [R 2 [] , R 1 [R 5 [], R 6 []]] 

--a
soma :: Num a => RTree a -> a 
soma (R x []) = x
soma (R x l) = x + sum ( map (soma) l )

--b
altura :: RTree a -> Int 
altura (R x []) = 1
altura (R x l) = 1 + maximum (map altura l)

--c
prune :: Int -> RTree a -> RTree a 
prune 0 (R x l) = R x []
prune y (R x l) = (R x (map (prune (y-1)) l))

--d
mirror :: RTree a -> RTree a 
mirror (R x []) = (R x [])
mirror (R x l) = R x (map mirror (reverse l))

--3
data Ltree a = Tip a | Fork (Ltree a) (Ltree a) 
  deriving Show 

lt = Fork (Tip 2) (Fork (Fork (Tip 2)(Tip 3))(Tip 1))

--a
ltsum :: Num a => Ltree a -> a
ltsum (Tip x) = x
ltsum (Fork x y) = ltsum x + ltsum y

--b 
listalt :: Ltree a -> [a]
listalt (Tip x) = [x]
listalt (Fork x y) = listalt x ++ listalt y

--c
ltheight :: Ltree a -> Int 
ltheight (Tip x) = 1
ltheight (Fork x y) = 1 + max (ltheight x) (ltheight y)