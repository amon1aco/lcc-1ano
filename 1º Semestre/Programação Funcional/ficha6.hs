import Test.QuickCheck.Modifiers (NonEmptyList(getNonEmpty))
-- Ficha 6

--1

data BTree a = Empty | Node a (BTree a) (BTree a)
    deriving Show

bt = Node 7 (Node 4 (Node 2 Empty Empty)(Node 5 Empty Empty)) (Node 9 Empty (Node 10 Empty Empty))
bt1 = Node 3 (Node 4 (Node 1 Empty Empty)(Node 5 Empty Empty)) (Node 9 Empty Empty)

--a
altura :: BTree a -> Int
altura Empty = 0
altura (Node r e d) = max (1 + altura e) (1 + altura d)

--b
contanodos :: BTree a -> Int
contanodos Empty = 0
contanodos (Node r e d) = 1 + contanodos e + contanodos d


--c
folhas :: BTree a -> Int
folhas Empty = 0
folhas (Node r Empty Empty) = 1
folhas (Node r e d) = folhas e + folhas d

--d
prune :: Int -> BTree a -> BTree a
prune 0 _ = Empty
prune _ Empty = Empty
prune x (Node r e d) =  (Node r (prune (x-1) e) (prune (x-1) d))

--e
path :: [Bool] -> BTree a -> [a]
path [] _ = []
path _ Empty = []
path (x:y) (Node r e d) | x == False = r : path y e
                        | x == True = r : path y d

--f
mirror :: BTree a -> BTree a
mirror Empty = Empty
mirror (Node r e d) = (Node r (mirror d) (mirror e))

--g
zipwithbt :: (a -> b -> c) -> BTree a -> BTree b -> BTree c
zipwithbt f (Node x e1 d1) (Node y e2 d2) = 
   Node (f x y) (zipWithbt f e1 e2) (zipWithbt f d1 d2) 
zipWithbt _ _ _ = Empty
    -- Não percebi a função da "função", nem sei usar...

--h
unzipbt :: BTree (a,b,c) -> (BTree a,BTree b,BTree c)
unzipnt Empty = (Empty,Empty,Empty)
unzipbt (Node (x,y,z) e d) = 
    let (a1,b1,c1) = unzipbt e
        (a2,b2,c2) = unzipbt d
    in (Node x a1 a2, Node y b1 b2, Node z c1 c2)
    -- Não percebi a função da "função", nem sei usar...

--2
--a
minimo :: Ord a => BTree a -> a
minimo (Node r Empty _) = r
minimo (Node r e d) = minimo e

--b
semmin :: Ord a => BTree a -> BTree a
semmin (Node r Empty _) = Empty
semmin (Node r e d) = (Node r (semmin e) d)

--c
both :: Ord a => BTree a -> (a,BTree a)
both (Node r Empty d) = (r, d)
both (Node r e d) = (a, Node r b d) 
       where (a,b) = both e
    -- Foda

--d
remove :: Ord a => a -> BTree a -> BTree a
remove x (Empty) = Empty
remove x (Node r e d) | x < r = Node r (remove x e) d
                      | x > r = Node r e (remove x d)
                      | x == r = aux x (Node r e d)
    where aux n (Node a b c) = case b of
                                Empty -> c
                                otherwise -> case c of Empty -> b
                                                       otherwise -> Node g b h
          (g,h) = both d
  -- Da linha 87 pra baixo ta foda..