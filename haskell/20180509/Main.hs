-- Exercises of basics of Haskell functions:

-- delete y from list (x:xs)
delete :: Eq a => a -> [a] -> [a]
delete _ [] = []
delete y (x:xs) | y == x = delete y xs
                | otherwise = x: delete y xs

-- calculate the sum (+) of a list
-- augmenting recursion
total :: Num a => [a] -> a
total [] = 0
total (x:xs) = x + total xs
-- tail recursion
total' :: Num a => [a] -> a -> a
total' [] n = n
total' (x:xs) n = total' xs $! (n+x)
-- total' (x:xs) !n = total' xs (n+x)

-- Mutual recursion
-- Note that declaration of a function should be placed together
even' :: Int -> Bool
even' 0 = True
even' n = odd' (n-1)
odd' :: Int -> Bool
odd' 0 = False
odd' n = even' (n-1)

-- 91 function of McCarthy
-- Always return 91 if n < 100
mc :: Int -> Int
mc n | n > 100 = n - 10
     | otherwise = mc $ mc $ n + 11

-- Convert Decimals to Romes (<= 5000)
romeNotation :: [String]
romeNotation = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
romeAmount :: [Int]
romeAmount = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
romeDict :: [(Int, String)]
romeDict = zip romeAmount romeNotation
-- Get the Largest rome
subtrahend :: Int -> (Int, String)
subtrahend n = head $ dropWhile (\(a,_) -> a > n) romeDict
convert :: Int -> (Int, String)
convert 0 = (0, "")
convert n = let (i, st) = subtrahend n in
            let (i', st') = convert (n-i) in (i', st ++ st')

-- SEARCHING
-- binary search
binarySearch :: Ord a => a -> [a] -> Bool
binarySearch _ [] = False
binarySearch a xs | m < a = binarySearch a behind
                  | m > a = binarySearch a front
                  | otherwise = True
                    where (front, m:behind) = splitAt (length xs `div` 2) xs

-- SORTING
-- Insertion sort
---- insert x ys
---- ys is a sorted list (ascending)
---- insert x in ys keeping it sorted
insert :: Ord a => a -> [a] -> [a]
insert x [] = [x]
insert x (y:ys) | x < y = x:y:ys
                | otherwise = y: insert x ys

---- insertionSort xs ys
---- xs is a sorted list, ys is an unsorted list
---- insert each element in ys to xs
---- (tail recursion)
insertionSort :: Ord a => [a] -> [a] -> [a]
insertionSort xs [] = xs
insertionSort xs (y:ys) = insertionSort (insert y xs) ys
---- (augmenting recursion)
insertionSort' :: Ord a => [a] -> [a]
insertionSort' [] = []
insertionSort' (x:xs) = insert x (insertionSort' xs)

-- bubble sort
swapFirstSecond :: Ord a => [a] -> [a]
swapFirstSecond [] = []
swapFirstSecond [x] = [x]
swapFirstSecond (x1:x2:xs) | x1 > x2 = x2: swapFirstSecond (x1:xs)
                           | otherwise = x1: swapFirstSecond (x2:xs)
---- apply f on x until x is a fixed point of f
fix :: Eq a => (a -> a) -> a -> a
fix f x = if x == x' then x else fix f x'
            where x' = f x
bubbleSort :: Ord a => [a] -> [a]
bubbleSort xs = fix swapFirstSecond xs

main :: IO()
main = do
    putStrLn ">> [ test function ] delete"
    putStrLn $ show $ delete 2 [2, 3, 4, 3, 2, 5, 2, -1, 2]
    putStrLn ">> [ test function ] total / total'"
    putStrLn $ show $ total [1, 2, 3, 4, 5]
    putStrLn $ show $ total' [1, 2, 3, 4, 5] 0
    putStrLn ">> [ test function ] McCarthy 91 function"
    putStrLn $ show $ mc 50
    putStrLn ">> [ test function ] even' / odd'"
    putStrLn $ (show $ even' 10) ++ ", " ++ (show $ odd' 10)
    putStrLn ">> [ test function ] decimal to roman"
    putStrLn $ show $ convert 4396
    putStrLn ">> [ test function ] binary search"
    putStrLn $ show $ binarySearch 4 [1,2,2,3,3,3,3,5,6,7]
    putStrLn ">> [ test function ] insertionSort / insertionSort'"
    putStrLn $ show $ insertionSort [] [3,8,7,5,6,1,7,8,9]
    putStrLn $ show $ insertionSort' [3,8,7,5,6,1,7,8,9]
