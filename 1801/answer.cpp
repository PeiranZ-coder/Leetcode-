class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MOD = 1e9 + 7;

        // {价格, 数量}
        // 买单：大根堆（堆顶是最高买价）
        priority_queue<pair<int,int>> buy_heap;
        // 卖单：小根堆（堆顶是最低卖价）
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> sell_heap;

        for (auto& order : orders) {
            int price  = order[0];
            int amount = order[1];
            int type   = order[2];

            if (type == 0) {
                // 买单：尝试和卖单簿撮合
                while (amount > 0 && !sell_heap.empty() && sell_heap.top().first <= price) {
                    auto [sell_price, sell_amount] = sell_heap.top();
                    sell_heap.pop();

                    int matched = min(amount, sell_amount);
                    amount      -= matched;
                    sell_amount -= matched;

                    if (sell_amount > 0) {
                        sell_heap.push({sell_price, sell_amount});  // 卖单未完全成交，放回
                    }
                }
                if (amount > 0) {
                    buy_heap.push({price, amount});  // 未成交部分进积压
                }
            } else {
                // 卖单：尝试和买单簿撮合
                while (amount > 0 && !buy_heap.empty() && buy_heap.top().first >= price) {
                    auto [buy_price, buy_amount] = buy_heap.top();
                    buy_heap.pop();

                    int matched = min(amount, buy_amount);
                    amount     -= matched;
                    buy_amount -= matched;

                    if (buy_amount > 0) {
                        buy_heap.push({buy_price, buy_amount});  // 买单未完全成交，放回
                    }
                }
                if (amount > 0) {
                    sell_heap.push({price, amount});  // 未成交部分进积压
                }
            }
        }

        // 统计积压订单总数
        long long total = 0;
        while (!buy_heap.empty()) {
            total = (total + buy_heap.top().second) % MOD;
            buy_heap.pop();
        }
        while (!sell_heap.empty()) {
            total = (total + sell_heap.top().second) % MOD;
            sell_heap.pop();
        }

        return (int)total;
    }
};
