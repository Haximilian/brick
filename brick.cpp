namespace Brick {
    int current_transaction = 1;

    int start_transaction() {
        return current_transaction++;
    }
}