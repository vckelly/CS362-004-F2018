CFLAGS= -Wall -Wextra -g -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	
	echo "Result for running Unit tests:" > tests.out
	echo "unittest1.c:" >> tests.out
	gcc -o unittest1 unittest1.c dominion.o rngs.o $(CFLAGS)
	unittest1 >> tests.out
	gcov unittest1.c >> tests.out
	
	echo "unittest2.c:" >> tests.out
	gcc -o unittest2 unittest2.c dominion.o rngs.o $(CFLAGS)
	unittest2 >> tests.out
	gcov unittest2.c >> tests.out
	
	echo "unittest3.c:" >> tests.out
	gcc -o unittest3 unittest3.c dominion.o rngs.o $(CFLAGS)
	unittest3 >> tests.out
	gcov unittest3.c >> tests.out
	
	echo "unittest4.c:" >> tests.out
	gcc -o unittest4 unittest4.c dominion.o rngs.o $(CFLAGS)
	unittest4 >> tests.out
	gcov unittest4.c >> tests.out

	echo "Result for running Card tests:" >> tests.out
	echo "cardtest1.c:" >> tests.out
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS)
	cardtest1 >> tests.out
	gcov cardtest1.c >> tests.out

	echo "cardtest2.c:" >> tests.out
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o $(CFLAGS)
	cardtest2 >> tests.out
	gcov cardtest2.c >> tests.out

	echo "cardtest3.c:" >> tests.out
	gcc -o cardtest3 cardtest3.c dominion.o rngs.o $(CFLAGS)
	cardtest3 >> tests.out
	gcov cardtest3.c >> tests.out

	echo "cardtest4.c:" >> tests.out
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o $(CFLAGS)
	cardtest4 >> tests.out
	gcov cardtest4.c >> tests.out

randomtestresults: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.o rngs.o

	echo "randomtestadventurer.c:" > randomtestadventurer.out
	gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer &> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out
	
	echo "randomtestcard2.c:" > randomtestcard2.out
	gcc -o randcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	./randcard2 &> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	
	echo "randomtestcard1.c:" > randomtestcard1.out
	gcc -o randcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	./randcard1 &> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe tests.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randcard1 randcard2 randomtestadventurer 
