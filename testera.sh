printf "Erreur(s) de la norminette:\n \033[91m"
norminette ft_*.c | grep "Error!"
printf "\033[0m\n"
read -p "If no line are output are outputted norminette is OK, please press enter to clone the testers"

echo "cloning repositories..."
rm -rf tripouille notjustjoe 5IGI0 Ysoroko alelievr warmachine
git clone https://github.com/tripouille/libftTester.git "tripouille"
git clone https://github.com/notjustjoe/libfttester.git "notjustjoe"
git clone https://github.com/5IGI0/libftsigtest.git "5IGI0"
git clone https://github.com/Ysoroko/FT_SPLIT_TESTER.git "Ysoroko"
git clone https://github.com/alelievr/libft-unit-test.git "alelievr"
git clone https://github.com/0x050f/libft-war-machine.git "warmachine"

read -p "Press enter to run first test"
osascript -e 'tell app "Terminal" to do script "cd \"'`pwd`'/tripouille\"
make a
rm -rf ../tripouille"'

read -p "Press enter to run next test"
osascript -e 'tell app "Terminal" to do script "cd \"'`pwd`'/notjustjoe\"
make all
rm -rf ../notjustjoe"'

read -p "Press enter to run next test"
osascript -e 'tell app "Terminal" to do script "cd \"'`pwd`'/Ysoroko\"
make all
rm -rf ../Ysoroko"'

read -p "Press enter to run next test"
osascript -e 'tell app "Terminal" to do script "cd \"'`pwd`'/alelievr\"
make LIBFTDIR=..
./run_test
rm -rf ../alelievr"'

read -p "Press enter to run next test"
osascript -e 'tell app "Terminal" to do script "cd \"'`pwd`'/5IGI0\"
make all 
rm -rf ../5IGI0"'

read -p "Press enter to run last test (must be run when all the other tests are finished !)"
osascript -e 'tell app "Terminal" to do script "cd \"'`pwd`'/warmachine\"
./grademe.sh
./grademe.sh
rm -rf ../warmachine"'