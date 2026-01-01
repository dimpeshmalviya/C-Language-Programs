import math

def generate_sine_wave(amplitude, frequency, samples):
    values = []
    for i in range(samples):
        x = i * frequency
        y = amplitude * math.sin(x)
        values.append((x, y))
    return values


# Example usage
wave = generate_sine_wave(1, 0.5, 10)
print("Sine wave values:")
for point in wave:
    print(point)
