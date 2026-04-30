import matplotlib.pyplot as plt

# -----------------------------
# Experiment 1 Data
# -----------------------------
temp = [58.10, 53.45, 49.05, 44.10, 39.52, 35.10, 31.90]
vout = [4.31, 3.68, 3.02, 2.41, 1.67, 0.98, 0.52]
r_ntc = [2.382, 2.895, 3.498, 4.263, 5.122, 6.352, 8.041]

# Sort data for clean graph (ascending temperature)
temp_sorted, vout_sorted, r_sorted = zip(*sorted(zip(temp, vout, r_ntc)))

# -----------------------------
# Graph 1: Voltage & Resistance vs Temperature
# -----------------------------
fig, ax1 = plt.subplots()

ax1.set_xlabel('Temperature (°C)')
ax1.set_ylabel('Vout (V)')
ax1.plot(temp_sorted, vout_sorted, marker='o')
ax1.grid(True)

ax2 = ax1.twinx()
ax2.set_ylabel('R_NTC (kΩ)')
ax2.plot(temp_sorted, r_sorted, marker='o')

plt.title('Voltage and Resistance vs Temperature')
plt.show()

# -----------------------------
# Experiment 2 Data
# -----------------------------
time = ["12:00","12:30","1:00","1:30","2:00","2:30","3:00","3:30","4:00","4:30","5:00","5:30","6:00"]
temp_room = [31.2,30.9,32.1,33.2,32.6,32.2,33.1,33.3,34.1,33.0,32.4,31.3,30.9]

# -----------------------------
# Graph 2: Room Temperature vs Time
# -----------------------------
plt.figure()

plt.plot(time, temp_room, marker='o')
plt.xlabel('Time')
plt.ylabel('Temperature (°C)')
plt.title('Room Temperature Variation')
plt.xticks(rotation=45)
plt.grid(True)

plt.tight_layout()
plt.show()