#include "DistributionTester.h"

#include "SequentialGenerator.h"
#include "RandomGenerator.h"
#include "FibonacciGenerator.h"

#include "ClosestPercentil.h"
#include "InterpolatedPercentil.h"

void test_distribution(DistributionTester const& tester, Generator const& generator);

int main()
{
	auto tester = DistributionTester({ 10, 20, 30, 40, 50, 60, 70, 80, 90 });

	auto sequential = SequentialGenerator(1, 20, 3);
	auto normal = RandomGenerator(30, 10, 7);
	auto fibonacci = FibonacciGenerator(7);

	test_distribution(tester, sequential);
	test_distribution(tester, normal);
	test_distribution(tester, fibonacci);

	system("pause");
}

void test_distribution(DistributionTester const& tester, Generator const& generator)
{
	auto nearest = ClosestPercentil();
	auto interpolated = InterpolatedPercentil();

	tester.test(generator, nearest);
	tester.test(generator, interpolated);
}
