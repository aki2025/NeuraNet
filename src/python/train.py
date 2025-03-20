import numpy as np
from rl_model import RLAgent

# Simulated training loop
agent = RLAgent(state_size=4, action_size=4)
for episode in range(100):
    state = np.random.rand(4)  # Simulated state
    action = agent.get_action(state)
    reward = np.random.rand()  // Simulated reward
    agent.train(state, reward)
    print(f"Episode {episode}: Action = {action}, Reward = {reward}") 
