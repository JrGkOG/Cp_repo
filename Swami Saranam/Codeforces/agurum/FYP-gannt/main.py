import matplotlib.pyplot as plt
import pandas as pd
import matplotlib.dates as mdates
from matplotlib.patches import Patch

# ----------------------------
# Timeline Data
# ----------------------------
data = [

    # Finished Phase
    ["2025-12-01","2026-02-28","Finished","Literature survey"],
    ["2025-1-01","2026-02-28","Finished","Problem definition"],
    ["2025-12-01","2026-02-28","Finished","Problem statement refinement"],

    # Active Phases
    ["2026-03-01","2026-05-31","Active","Distributed Island Model framework"],
    ["2026-04-01","2026-06-30","Active","Migration topology and structured logging system"],
    ["2026-06-01","2026-08-31","Active","Large-scale distributed experimental runs"],
    ["2026-08-01","2026-09-30","Active","Data validation and trajectory dataset structuring"],
    ["2026-09-01","2026-12-31","Active","Scalable clustering pipeline development"],
    ["2026-10-15","2027-01-15","Active","Clustering parameter tuning and stability testing"],
    ["2026-11-01","2027-02-28","Active","Archipelago-STN graph construction"],
    ["2027-01-01","2027-02-28","Active","Traditional STN baseline implementation"],
    ["2027-02-01","2027-03-31","Active","Structural metrics computation and comparative analysis"],
    ["2026-10-01","2027-04-30","Active","Statistical validation and robustness analysis"],
    ["2026-09-01","2027-04-30","Active","Thesis writing and documentation"]
]

df = pd.DataFrame(data, columns=["Start","End","Status","Task"])

df["Start"] = pd.to_datetime(df["Start"], format="%Y-%m-%d")
df["End"] = pd.to_datetime(df["End"], format="%Y-%m-%d")
df["Duration"] = (df["End"] - df["Start"]).dt.days

# ----------------------------
# Colors
# ----------------------------
AMRITA_MAROON = "#A4123F"
GREY = "#7f7f7f"
BLACK = "#000000"

color_map = {
    "Finished": GREY,
    "Active": AMRITA_MAROON
}

# ----------------------------
# Plot
# ----------------------------
plt.figure(figsize=(16, 9))  # wider figure

bar_height = 0.35

for i, row in df.iterrows():
    plt.barh(
        y=i,
        width=row["Duration"],
        left=row["Start"],
        height=bar_height,
        color=color_map[row["Status"]],
        edgecolor=BLACK
    )

plt.yticks(range(len(df)), df["Task"])
plt.xlabel("Timeline", color=BLACK)
plt.title("STN Research Timeline (Dec 2025 – April 2027)", color=BLACK)
plt.gca().invert_yaxis()

# ----------------------------
# Proper X-axis Spacing
# ----------------------------
ax = plt.gca()

# Show tick every 2 months
ax.xaxis.set_major_locator(mdates.MonthLocator(interval=2))
ax.xaxis.set_major_formatter(mdates.DateFormatter('%b %Y'))

plt.xticks(rotation=30)  # rotate slightly for readability

plt.grid(axis='x', linestyle='--', alpha=0.3)

# Legend
legend_elements = [
    Patch(facecolor=GREY, edgecolor=BLACK, label="Finished (Literature & Refinement)"),
    Patch(facecolor=AMRITA_MAROON, edgecolor=BLACK, label="Active / Planned Phases")
]

plt.legend(
    handles=legend_elements,
    loc='upper center',
    bbox_to_anchor=(0.5, 1.08),
    ncol=2,
    frameon=False
)

plt.tight_layout()
plt.show()
