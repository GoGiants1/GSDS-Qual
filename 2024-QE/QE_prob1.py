from collections import deque


class TNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def height(T: TNode) -> int:
    if T.left is None and T.right is None:
        return 0

    q = deque()
    q.append([0, T])
    max_height = 0

    while q:
        h, T = q.popleft()
        max_height = max(max_height, h)
        if T.left:
            q.append((h + 1, T.left))
        if T.right:
            q.append((h + 1, T.right))

    return max_height


def is_balanced(T: TNode) -> bool:
    # 모든 노드에서 left, right subtree height의 차이가 at most 1이어야함.
    # TODO: Debugging
    if T.left is None and T.right is None:
        return True

    h_l = height(T.left) if T.left else 0
    h_r = height(T.right) if T.right else 0

    if abs(h_l - h_r) > 1:
        return False

    left = is_balanced(T.left) if T.left else True
    right = is_balanced(T.right) if T.right else True

    if left is True and right is True:
        return True

    return False


def is_bst(T: TNode) -> bool:
    if T.left is None and T.right is None:
        return True
    is_left_ok = False
    is_right_ok = False
    if T.left is None or (T.left is not None and T.left.val <= T.val):
        is_left_ok = True

    if T.right is None or (T.right is not None and T.right.val >= T.val):
        is_right_ok = True

    if is_left_ok and is_right_ok:
        left_sub_tree = is_bst(T.left) if T.left else True
        right_sub_tree = is_bst(T.right) if T.right else True
        return left_sub_tree and right_sub_tree

    return False


def common_ancestors(T: TNode, U: TNode, V: TNode) -> list[int]:
    # T는 루트 노드
    # U, V는 트리 내의 노드 두개
    # return 은 value of LCA

    def dfs(root: TNode, target: TNode) -> list[int]:
        if root.val == target.val:
            return [target.val]
        if root.left is None and root.right is None:
            return []
        current_path = [root.val]
        if root.left:
            sub_path = dfs(root.left, target)
            if len(sub_path) > 0:
                current_path.extend(sub_path)
                return current_path
        if root.right:
            sub_path = dfs(root.right, target)
            if len(sub_path) > 0:
                current_path.extend(sub_path)
                return current_path
        return []

    p1 = dfs(T, U)
    p2 = dfs(T, V)
    min_len = min(len(p1), len(p2))
    ret = []

    for i in range(min_len):
        if p1[i] == p2[i]:
            ret.append(p1[i])
        else:
            break
    return ret


def lca(T: TNode, U: TNode, V: TNode) -> int:
    return common_ancestors(T, U, V)[-1]


# if __name__ == "__main__":
#     T7, T8, T9 = TNode(4), TNode(9), TNode(13)
#     T3, T4 = TNode(1), TNode(6, T7, None)
#     T5, T6 = TNode(11, T8, T9), TNode(20)
#     T1, T2 = TNode(3, T3, T4), TNode(15, T5, T6)
#     T0 = TNode(8, T1, T2)

#     print(height(T0))
#     print(is_bst(T0))
#     print(is_balanced(T0))

#     ####
#     T7, T8, T9 = TNode(7), TNode(5), TNode(9)
#     T3, T4 = TNode(1), TNode(4, T7, None)
#     T5, T6 = TNode(20, T8, T9), TNode(6)
#     T1, T2 = TNode(3, T3, T4), TNode(15, T5, T6)
#     T0 = TNode(8, T1, T2)

#     print(is_bst(T0))
#     print(common_ancestors(T0, T6, T8))
#     print(common_ancestors(T0, T1, T7))
#     print(lca(T0, T1, T7))
