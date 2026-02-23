#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice, sizeChoice, quantity, nonOrVeg, periperi;
    float total = 0;

    const float taxRate = 0.05;
    const float discountRate = 0.10;

    string items[50];
    float prices[50];
    int count = 0;

    cout << "=========================================\n";
    cout << " Welcome To McDonald's 🍔🍟\n";
    cout << " Exercise? Oh I heard extra fries 😌\n";
    cout << "=========================================\n";

    while (true)
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Burger\n";
        cout << "2. Fries\n";
        cout << "3. Coke\n";
        cout << "4. McFlurry\n";
        cout << "5. Checkout\n";

        cout << "\nChoose your item: ";
        cin >> choice;

        if (choice == 5)
            break;

        switch (choice)
        {
        case 1:
        {
            cout << "1. Veg (₹250)\n";
            cout << "2. Non-Veg (₹280)\n";
            cout << "\nChoose Burger Type: ";
            cin >> nonOrVeg;

            string type = (nonOrVeg == 1) ? "Veg" : "Non-Veg";
            float price = (nonOrVeg == 1) ? 250 : 280;

            cout << "\nEnter quantity: ";
            cin >> quantity;

            total += price * quantity;
            items[count] = type + " Burger " +"x " + to_string(quantity);
            prices[count] = price * quantity;
            count++;

            cout << "\n✅ Burger added successfully!\n";
            break;
        }

        case 2:
        {
            cout << "1. Medium - ₹100\n";
            cout << "2. Large  - ₹150\n";
            cout << "\nChoose Fries Size: ";
            cin >> sizeChoice;

            float price = (sizeChoice == 1) ? 100 : 150;
            string size = (sizeChoice == 1) ? "Medium" : "Large";

            cout << "1. Yes (+₹30)\n";
            cout << "2. No\n";
            cout << "\nPeri Peri Add-On? ";
            cin >> periperi;

            string addon = "";
            if (periperi == 1)
            {
                price += 30;
                addon = " + Peri Peri";
            }

            cout << "\nEnter quantity: ";
            cin >> quantity;

            total += price * quantity;
            items[count] = "Fries (" + size + addon + ") x" + to_string(quantity);
            prices[count] = price * quantity;
            count++;

            cout << "\n✅ Fries added to cart\n";
            break;
        }

        case 3:
        {
            cout << "1. Medium - ₹90\n";
            cout << "2. Large  - ₹120\n";
            cout << "\nChoose Coke Size: ";
            cin >> sizeChoice;

            float price = (sizeChoice == 1) ? 90 : 120;
            string size = (sizeChoice == 1) ? "Medium" : "Large";

            cout << "\nEnter quantity: ";
            cin >> quantity;

            total += price * quantity;
            items[count] = "Coke (" + size + ") x" + to_string(quantity);
            prices[count] = price * quantity;
            count++;

            cout << "\n✅ Coke added to cart\n";
            break;
        }

        case 4:
        {
            cout << "Enter Quantity: ";
            cin >> quantity;

            total += 220 * quantity;
            items[count] = "McFlurry x" + to_string(quantity);
            prices[count] = 220 * quantity;
            count++;

            cout << "\n✅ McFlurry added\n";
            break;
        }

        default:
            cout << "\n❌ Invalid choice.Try again.\n";
        }
    }

    float tax = total * taxRate;
    float discount = total * discountRate;
    float finalBill = total + tax - discount;

    cout << "\n=========== BILL ===========\n";
    for (int i = 0; i < count; i++)
    {
        cout << items[i] << "  ₹" << prices[i] << endl;
    }

    cout << "----------------------------\n";
    cout << "Subtotal : ₹" << total << endl;
    cout << "Tax (5%) : ₹" << tax << endl;
    cout << "Discount : ₹" << discount << endl;
    cout << "Final Bill: ₹" << finalBill << endl;

    cout << "\nThanks for ordering — I'm lovin' it 🍟❤️\n";

    return 0;
}