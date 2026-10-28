import tensorflow as tf
from keras.src.utils import data_utils

original_get_file = data_utils.get_file

def patched_get_file(fname, origin, *args, **kwargs):
    if "cifar-10-python.tar.gz" in origin:
        origin = (
            "https://huggingface.co/datasets/MIT-OL-AI-D/"
            "cifar-10-python/resolve/main/cifar-10-python.tar.gz"
        )
    return original_get_file(fname, origin, *args, **kwargs)

data_utils.get_file = patched_get_file

# Original API remains unchanged
(x_train, y_train), (x_test, y_test) = (
    tf.keras.datasets.cifar10.load_data()
)

print(x_train.shape, y_train.shape)
print(x_test.shape, y_test.shape)
