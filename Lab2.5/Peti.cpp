#include "NumberSequence.h"

#include "FileSource.h"
#include "KeyboardSource.h"

#include "AverageObserver.h"
#include "LoggerObserver.h"
#include "MedianObserver.h"
#include "SumObserver.h"

void test_sequence(NumberSequence& sequence);

int main()
{
    test_sequence(NumberSequence(std::make_shared<FileSource>("numbers.txt")));
    test_sequence(NumberSequence(std::make_shared<KeyboardSource>()));

    system("pause");
}

void test_sequence(NumberSequence& sequence)
{
    LoggerObserver log("log.txt");
    auto sum = SumObserver();
    auto avg = AverageObserver();
    auto med = MedianObserver();

    sequence.register_observer(log);
    sequence.register_observer(sum);
    sequence.register_observer(avg);
    sequence.register_observer(med);

    sequence.start();

    sequence.remove_observer(log);
    sequence.remove_observer(sum);
    sequence.remove_observer(avg);
    sequence.remove_observer(med);
}
