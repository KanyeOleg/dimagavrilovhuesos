pipeline {
    agent any
    
    parameters {
        choice(name: 'BUILD_TYPE', choices: ['develop', 'prod'], description: 'Тип сборки')
    }
    
    environment {
        APP_VERSION_MAJOR = '1'
        APP_VERSION_MINOR = '0'
        APP_VERSION_PATCH = '0'
    }
    
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        
        stage('Build') {
            steps {
                script {
                    if (params.BUILD_TYPE == 'develop') {
                        sh 'make build'
                    } else {
                        sh 'make BUILD_TYPE=release build'
                    }
                }
            }
        }
        
        stage('Test') {
            steps {
                sh 'make test'
            }
        }
    }
    
    post {
        always {
            sh 'make clean'
        }
    }
}
