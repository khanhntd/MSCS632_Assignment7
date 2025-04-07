from collections import Counter

class Statistics:
    def __init__(self, data):
        self.data = data

    def mean(self):
        return sum(self.data) / len(self.data)

    def median(self):
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        if n % 2 == 1:
            return sorted_data[n // 2]
        else:
            return (sorted_data[n // 2 - 1] + sorted_data[n // 2]) / 2

    def mode(self):
        data_count = Counter(self.data)
        max_count = max(data_count.values())
        modes = [key for key, count in data_count.items() if count == max_count]
        return modes

# Example usage
data = [4, 5, 6, 7, 4, 3, 4]
stats = Statistics(data)

print(f"Mean: {stats.mean():.2f}")
print(f"Median: {stats.median():.2f}")
print(f"Mode(s): {', '.join(map(str, stats.mode()))}")