import torch
import torch.nn as nn

class PolicyNetwork(nn.Module):
    def __init__(self, input_size, output_size):
        super(PolicyNetwork, self).__init__()
        self.fc1 = nn.Linear(input_size, 128)
        self.fc2 = nn.Linear(128, output_size)
    
    def forward(self, x):
        x = torch.relu(self.fc1(x))
        return self.fc2(x)

class RLAgent:
    def __init__(self, state_size, action_size):
        self.model = PolicyNetwork(state_size, action_size)
        self.optimizer = torch.optim.Adam(self.model.parameters(), lr=0.001)

    def get_action(self, state):
        state_tensor = torch.FloatTensor(state)
        action = self.model(state_tensor).detach().numpy()
        return action

    def train(self, state, reward):
        state_tensor = torch.FloatTensor(state)
        action_pred = self.model(state_tensor)
        loss = -torch.mean(action_pred) * reward
        self.optimizer.zero_grad()
        loss.backward()
        self.optimizer.step() 
