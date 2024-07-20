module Ficha3 where

--1
data Hour = H Int Int
    deriving Show 

type Etapa = (Hour,Hour)
type Viagem = [Etapa]

vi = [(H 9 30, H 10 25),(H 11 20, H 12 45),(H 13 30, H 14 45 )]

valida1 :: Hour -> Bool
valida1 (H a b) = if a >= 0 && a < 24 && b >= 0 && b <= 59 then True else False

compara1 :: Hour -> Hour -> Bool
compara1 (H a b)(H c d) | a < c = True
                        | a == c && b < d = True
                        | otherwise = False

minutos1 :: Hour -> Int
minutos1 (H a b) = b + (60*a)

horas1 :: Int -> Hour 
horas1 x = (H (x `div` 60) (mod x 60))

diff1 :: Hour -> Hour -> Int
diff1 (H a b) (H c d) = minutos1 (H (abs (a-c))(abs (b-d)))

addmin1 :: Int -> Hour -> Hour
addmin1 x (H a b) = somah (horas1 x) (H a b)
  where somah :: Hour -> Hour -> Hour
        somah (H a b) (H c d) = (H (a+c)(b+d))

--a
bemfeita :: Viagem -> Bool 
bemfeita [] = True 
bemfeita ((H a b,H c d):e) | valida1 (H a b) && valida1 (H c d) && compara1 (H a b) (H c d) = bemfeita e
                           | otherwise = False

--b
bemfeita2 :: Viagem -> Bool 
bemfeita2 [] = True 
bemfeita2 [x] = bemfeita [x]
bemfeita2 ((H a b,H c d):e) | compara1 (H a b) (H c d) && compara1 (H c d)(fst $ head e) = bemfeita2 e 
                            | otherwise = False

--c
horas :: Viagem -> (Hour,Hour)
horas [(a,b)] = (a,b)
horas (a:b) = (fst a, snd $ last b)

--d 
{-
quantotempo :: Viagem -> Hour 
quantotempo [(a,b)] = horadiff a b 
quantotempo ((a,b):c) = addmin1 (minutos1 (quantotempo c)) (horadiff a b)
  
horadiff :: Hour -> Hour -> Hour 
horadiff (H a b)(H c d) = H (abs (a-c))(abs (b-d))
--e
tempoespera :: [Viagem] -> Hour 
tempoespera [(a,b)] = H 0 0 
tempoespera (a:b) = horadiff (snd a) (fst $ head b) + tempoespera b

--f
tt :: [Viagem] -> Hour 
tt [] = H 0 0 
tt l = horas1 $ diff1 (snd horas l) (fst horas l)
-}

-- 3
data Contacto = Casa Integer
        | Trab Integer
        | Tlm Integer
        | Email String
    deriving Show
type Nome = String
type Agenda = [(Nome, [Contacto])]


agenda = [("Maria", [Casa 93333333, Trab 253333333, Tlm 934444444, Email "mariazinha@gmail.com"]), ("Eduardo", [Trab 931234567, Email "eduardozinho@gmail.com"])]
--a
metemail :: Nome -> String -> Agenda -> Agenda
metemail x y [] = [(x,[Email y])]
metemail x y ((a, h:t):c) | x == a = (a, (h:t) ++ [Email y]):c
                                  | otherwise = metemail x y c
               --Pede uma função print...                   
--b
--aux :: [Contacto] -> Maybe a
aux [] = Nothing
aux ((Email h) :t) = Just h
aux (h:t) = aux t

--vermails :: Nome -> Agenda -> Maybe [String]
vermails _ [] = Nothing
vermails x ((a, h:t):c) | x == a = aux (h:t)
                          | otherwise = vermails x c
    -- Está a funcionar mas sem os tipos...

--c
contatinho :: [Contacto] -> [Integer]
contatinho contactos = [ x | (Tlm x) <- contactos ] ++ [ x | (Casa x) <- contactos ] ++ [ x | (Trab x) <- contactos ]

contato = [Casa 348, Trab 3563, Tlm 23423542, Email "ararea"]

--d
aux2 [] = Nothing
aux2  ((Casa h) :t) = Just h
aux2 (h:t) = aux2 t

casa :: Nome -> Agenda -> Maybe Integer
casa _ [] = Nothing
casa x ((a, h:t):c) | x == a = aux2 (h:t)
                      | otherwise = casa x c

{-
--4
type Dia = Int
type Mes = Int
type Ano = Int
type Name = String

data Data = D Dia Mes Ano
    deriving Show

type TabDN = [(Name,Data)]

tab = [("Eduardo", D 22 6 3),("Maria", D 10 2 99),("Zeca", D 1 1 20)]

--a
procura :: Nome -> TabDN -> Maybe Data
procura _ [] = Nothing
procura x ((a,b):c) | x == a = Just b
                    | otherwise = procura x c

--b
idade :: Data -> Nome -> TabDN -> Maybe Int
idade _ _ [] = Nothing
idade (D d m a) nome tabela = let
  Just (D x y z) = procura nome tabela
  anos | m > y            = a - z
       | m == y && d >= x = a - z
       | otherwise        = a - z - 1
  in if anos >= 0 then Just anos else Nothing

--c
anterior :: Data -> Data -> Bool
anterior (D a b c) (D x y z) | c < z = True
                             | c == z && b < y = True
                             | c == z && b == y && a < x = True
                             | c > z = False
                             | c == z && b > y = False
                             | c == z && b == y && a > x = False

--d 
ordena :: TabDN -> TabDN
ordena [] = []
ordena ((k,D g h j):c) = metai (k,D g h j) (ordena c)

--metai :: (Nome, Data) -> TabDN
metai (x,D d m a) [] = [(x,D d m a)]
metai (x,D d m a) ((k,D g h j):c) | anterior (D d m a) (D g h j) = (x,(D d m a)):(k,(D g h j)):c
                                  | not (anterior (D d m a) (D g h j)) = (k,D g h j) : metai (x,D d m a) c

--e
poridade:: Data -> TabDN -> [(Nome,Int)]
poridade _ [] = []
poridade (D d m a) tabela = (n,idade) : poridade (D d m a) ts
    where ((n,D dx mx ax):ts) = ordena tabela
          idade = if m > mx || mx == m && d > dx then a - ax else (a - ax) - 1
  -- Para ser honesto tenho dúvida na primeira linha do where
-}

-- Só está comentado porque os "datas" tem nomes semelhantes e interfere

--5
data Movimento = Credito Float | Debito Float
    deriving Show

data Data = D Int Int Int
    deriving Show

data Extracto = Ext Float [(Data, String, Movimento)]
    deriving Show

ext = Ext 100 [(D 8 12 21, "Fui às moças", Debito 20),(D 1 1 22, "Taremi", Credito 100)]

--a
extvalor :: Extracto -> Float -> [Movimento]
extvalor (Ext _ []) _ = []
extvalor (Ext x ((_,_, c):d)) w = case c of Credito n -> if n >= w then c : extvalor (Ext x d) w else extvalor (Ext x d) w
                                            Debito n -> if n >= w then c : extvalor (Ext x d) w else extvalor (Ext x d) w

--b
filtro :: Extracto -> [String] -> [(Data,Movimento)]
filtro (Ext _ []) _ = []
filtro (Ext x ((a,b,c):d)) s | elem b s = (a,c) : filtro (Ext x d) s
                             | otherwise = filtro (Ext x d) s

--c
credeb :: Extracto -> (Float,Float)
credeb (Ext _ []) = (0,0)
credeb (Ext x ((a,b,c):d)) = case c of 
                        Credito n -> (z + n, y)
                        Debito n -> (z,y + n)
                where (z,y) = credeb (Ext x d)
            
--d
saldo :: Extracto -> Float
saldo (Ext x []) = x
saldo (Ext x ((a,b,c):d)) = case c of 
                      Credito n -> saldo (Ext (x+n) d)
                      Debito n -> saldo (Ext (x-n) d)


