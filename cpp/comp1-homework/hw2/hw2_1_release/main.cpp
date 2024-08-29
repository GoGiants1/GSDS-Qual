#include "container.hpp"
#include <type_traits>

void Episode1()
{
    cout << "Episode 1:" << endl;
    float alloc_weight = 0;

    Carrier *carrier1 = new Carrier(100);
    carrier1->set_capacity();

    float carrier_size = carrier1->get_size();

    Bag *bag1 = new Bag(50);
    bag1->set_capacity();

    Box *box1 = new Box(10);

    PaperBox *pap_box1 = new PaperBox(10);
    pap_box1->set_capacity();
    PaperBox *pap_box2 = new PaperBox(10);
    pap_box2->set_capacity();

    PlasticBox *plas_box1 = new PlasticBox(10);
    plas_box1->set_capacity();
    PlasticBox *plas_box2 = new PlasticBox(10);
    plas_box2->set_capacity();

    carrier1->add_aux(plas_box1);
    carrier1->add_aux(plas_box2);

    Box *aux_box = carrier1->get_aux(1);

    alloc_weight += carrier1->get_capacity();
    alloc_weight += bag1->get_capacity();
    alloc_weight += pap_box1->get_capacity();
    alloc_weight += pap_box2->get_capacity();

    carrier1->set_container_code();
    bag1->set_container_code();
    pap_box1->set_container_code();
    plas_box1->set_container_code();

    string *code = carrier1->get_container_code();

    cout << "Total capacity:" << alloc_weight << endl;
    delete carrier1;
}

void Episode2()
{
    cout << "Episode 2:" << endl;
    float alloc_weight = 0;

    Carrier *carrier1 = new Carrier(150);
    carrier1->set_capacity();

    float carrier_size = carrier1->get_size();

    Bag *bag1 = new Bag(30);
    bag1->set_capacity();
    Box *box1 = new Box(10);

    PaperBox *pap_box1 = new PaperBox(20);
    pap_box1->set_capacity();
    PaperBox *pap_box2 = new PaperBox(20);
    pap_box2->set_capacity();
    PlasticBox *plas_box1 = new PlasticBox(10);
    plas_box1->set_capacity();

    carrier1->add_aux(plas_box1);

    alloc_weight += carrier1->get_capacity();
    alloc_weight += bag1->get_capacity();
    alloc_weight += pap_box1->get_capacity();
    alloc_weight += pap_box2->get_capacity();

    carrier1->set_container_code();
    bag1->set_container_code();
    pap_box1->set_container_code();
    plas_box1->set_container_code();

    string *code = carrier1->get_container_code();

    cout << "Total capacity:" << alloc_weight << endl;
    delete carrier1;
}

int main(void)
{
    Episode1();
    cout << endl;
    Episode2();

    Bag myBag(10);
    myBag.set_capacity();
    Box myBox(20);
    myBox.set_capacity();
    PaperBox myPaperBox(30);
    PlasticBox myPlasticBox(40);
    Carrier myCarrier(50);

    myPaperBox.set_capacity();
    myPlasticBox.set_capacity();
    myCarrier.set_capacity();

    myCarrier.add_aux(new PaperBox(25));
    myCarrier.add_aux(new PlasticBox(35));

    myBag.set_container_code();
    std::cout << "Bag capacity: " << myBag.get_capacity() << std::endl;
    std::cout << "Bag code: " << *myBag.get_container_code() << std::endl;
}
