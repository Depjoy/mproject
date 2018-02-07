import pandas
def get_iris_data():
    '''
    get iris data for test
    '''
    url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"
    names = ['sepal_length', 'sepal_width','petal_length', 'petal_width', 'class']
    dataset = pandas.read_csv(url, names=names)
    return dataset

#get description
def get_iris_description():
    '''
    get iris data's description
    '''
    return  get_iris_data().describe()

def get_iris_column(column):
    '''
    get iris data with column's num
    Get a column of data
    :param column: column's number
    '''
    return get_iris_data().iloc[:,0]

def get_iris_row_data(row):
    return get_iris_data().head(row)
